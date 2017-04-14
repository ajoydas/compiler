%x STRINGSTATE
%x SINGLECOM
%x MULTICOM
%x ERR
%{
#include<stdio.h>
#include<stdlib.h>
#include "SymbolTable.h"
#include "y.tab.h"

extern YYSTYPE yylval;
extern FILE *logout;
extern FILE *error;
extern FILE *symtable;
extern SymbolTable *table;

int line_count=1;

void yyerror(char *);
bool prac=false;
int templine=0;


string temp="";
string realstr="";

int arrchar[10][2]={{110,10},{116,9},{97,7},{98,8},{102,12},{48,0},{92,92},{114,13},{34,34},{118,11}};
%}
NEWLINE \n

WHITESPACE [ \t\f\r\v]+ 
LETTER [a-zA-Z]
DIGIT [0-9]
FLOAT_NUMBER [0-9]*[.]?[0-9]+(E[+-]?[0-9]+)?
CHARACTER '[A-Za-z0-9]'
CHARACTER_EX '\\[ntabfv0\\r"v]'
IDENTIFIER [A-Za-z_][A-Za-z0-9_]*


NON_IDENTIFIER [0-9]+[.]*[A-Za-z0-9_]+|[A-Za-z0-9_]+([.]+[A-Za-z0-9_]*)+
DECIMAL_POINT_ERROR [0-9]*[.]([0-9]*[.]+[0-9]*)*
ILL_FORMATTED_NUMBER [0-9]*([.]+[0-9]*)?([.]+[0-9]*)*E([0-9]*[.][0-9]*)([.][0-9]*)*|[.]+E([0-9]*)|[0-9]*[.]([0-9]*[.]+[0-9]*)*E([0-9]*)
EMPTY_CHAR ''
UNRECOGNIZED_CHAR '[^A-Za-z0-9_\']'|'\\[^ntabfv0\\r"v']'
MULTI_CHAR '[A-Za-z0-9 ][A-Za-z0-9 ]+'|'[A-Za-z0-9 ][^A-Za-z0-9 '\n]+'|'\\[A-Za-z0-9 ][A-Za-z0-9 ]+'
UNTERMINATED_CHAR '[A-Za-z0-9]*|'

%%

{WHITESPACE}    {}
{NEWLINE} {line_count++;}


"if"	{ return IF; }
"for"	{ return FOR; }
"do"	{ return DO; }
"int"	{ return INT; }
"float"	{ return FLOAT; }
"void"	{ return VOID; }
"switch"	{ return SWITCH; }
"default"	{ return DEFAULT; }
"else"	{ return ELSE; }
"while"	{ return WHILE; }
"break"	{ return BREAK; }
"return"	{ return RETURN;}
"case"	{ return CASE; }
"continue"	{ return CONTINUE;}
"println"	{return PRINTLN;}


{DIGIT}+ 	{
				SymbolInfo *s=new  SymbolInfo(yytext,"CONST_INT");
				s->ivalue = atoi(yytext);
				yylval = (YYSTYPE)s;
				return CONST_INT;
			}

{FLOAT_NUMBER}	{
				SymbolInfo *s=new  SymbolInfo(yytext,"CONST_FLOAT");
				s->fvalue = atof(yytext);
				yylval = (YYSTYPE)s;
				return CONST_FLOAT;
			}
{CHARACTER}	{
				SymbolInfo *s = new  SymbolInfo(yytext,"CHAR_CONST");
				s->c = yytext[1];
				yylval = (YYSTYPE)s;
				return CONST_CHAR;
			}
{CHARACTER_EX}	{
				SymbolInfo *s = new  SymbolInfo(yytext,"CHAR_CONST");
				for(int i=0;i<10;i++)
				{
				    if(yytext[2]==arrchar[i][0]){
					    s->c = arrchar[i][1];
					    break;
				    }
				}
				yylval = (YYSTYPE)s;
				return CONST_CHAR;
			}

{IDENTIFIER}	{
				SymbolInfo *s=new  SymbolInfo(yytext,"ID");
				yylval = (YYSTYPE)s;
				return ID;
			}

[+-]		{
			SymbolInfo *s= new  SymbolInfo(yytext,"ADDOP");
			yylval = (YYSTYPE)s;
			return ADDOP;
			}
[*/%]		{
			SymbolInfo *s= new  SymbolInfo(yytext,"MULOP");
			yylval = (YYSTYPE)s;
			return MULOP;
			}
"++"		{ return INCOP; }

"--"		{ return DECOP; }

"<"|"<="|">"|">="|"=="|"!="		{ return RELOP; }

"="		{ return ASSINOP; }

"&&"|"||"		{ return LOGICOP; }

"!"		{ return NOT; }

"(" 	{return LPAREN;}
")" 	{return RPAREN;}
"{" 	{return LCURL;}
"}" 	{return RCURL;}
"[" 	{return LTHIRD;}
"]" 	{return RTHIRD;}

","		{ return COMMA; }
";"		{ return SEMICOLON; }
		
"//"      { 
			BEGIN SINGLECOM;
			temp+="//";
		}
<SINGLECOM>{NEWLINE}     {
			line_count++;
			templine++;			
			}
<SINGLECOM>\\$    {}
<SINGLECOM>.$ {
			temp+=yytext;
			//fprintf(token,"<STRING>, %s\"> ",temp.c_str());
			fprintf(logout,"Line No. %d: Token <COMMENT> Lexeme %s found\n\n",line_count-templine,temp.c_str());
			BEGIN INITIAL;
			temp="";
			templine=0;
			return SINGLECOM;
			}
<SINGLECOM>.    {
			temp+=yytext;
			}

"/*"      { 
			BEGIN MULTICOM;
			temp+="/*";
		}
<MULTICOM>{NEWLINE}    {
			line_count++;
			templine++;
			temp+=yytext;			
			}
<MULTICOM>"*/"    {
			fprintf(logout,"Line No. %d: Token <COMMENT> Lexeme %s*/ found\n\n",line_count-templine,temp.c_str());
			BEGIN INITIAL;
			temp="";
			templine=0;
			return MULTICOM;
			}
<MULTICOM><<EOF>> {
			temp+=yytext;
			fprintf(logout,"Error at line %d: Unterminated comment %s\n\n",line_count-templine,temp.c_str());
			//error_count++;
			temp="";
			templine=0;
			BEGIN INITIAL;
			return MULTICOM;
			}
<MULTICOM>.    {
			temp+=yytext;
			}

{DECIMAL_POINT_ERROR} { 
//			BEGIN ERR;
			fprintf(logout,"Error at line %d: Too many decimal point %s\n\n",line_count,yytext);
			//error_count++;
			}
{ILL_FORMATTED_NUMBER} {
//BEGIN ERR;
			fprintf(logout,"Error at line %d: Ill formed number %s\n\n",line_count,yytext);
			//error_count++;
			}
{NON_IDENTIFIER}  {
//BEGIN ERR;
			fprintf(logout,"Error at line %d: Invalid prefix on ID or invalid suffix on Number %s\n\n",line_count,yytext);
			//error_count++;
		}
{EMPTY_CHAR} {
//BEGIN ERR;
			fprintf(logout,"Error at line %d: Empty character constant error %s \n\n",line_count,yytext);
			//error_count++;
			}
{UNTERMINATED_CHAR} {
//BEGIN ERR;
			fprintf(logout,"Error at line %d: Unterminated character %s\n\n",line_count,yytext);
			//error_count++;
			}
{UNRECOGNIZED_CHAR} {
//BEGIN ERR;
			fprintf(logout,"Error at line %d: Unrecognized character %s\n\n",line_count,yytext);
			//error_count++;
			}
{MULTI_CHAR} {
//BEGIN ERR;
			fprintf(logout,"Error at line %d: Multi character constant error %s\n\n",line_count,yytext);
			//error_count++;
			}
<ERR>{NEWLINE}    {
			line_count++;}
<ERR>[;)}\]]    {
if(strcmp(yytext,")")==0)		{
			//fprintf(token,"<RPAREN, %s> ",yytext);
			fprintf(logout,"Line no %d: TOKEN <RPAREN> Lexeme %s found\n\n",line_count,yytext);
			}
if(strcmp(yytext,"}")==0)		{
			//fprintf(token,"<RCURL, %s> ",yytext);
			fprintf(logout,"Line no %d: TOKEN <RCURL> Lexeme %s found\n\n",line_count,yytext);
			}
if(strcmp(yytext,"]")==0)		{
			//fprintf(token,"<RTHIRD, %s> ",yytext);
			fprintf(logout,"Line no %d: TOKEN <RTHIRD> Lexeme %s found\n\n",line_count,yytext);
			}
if(strcmp(yytext,";")==0)    	{
			//fprintf(token,"<SEMICOLON, %s> ",yytext);
			fprintf(logout,"Line no %d: TOKEN <SEMICOLON> Lexeme %s found\n\n",line_count,yytext);
			}
			//BEGIN INITIAL;
}
<ERR>.    {}

<<EOF>> 	{
			line_count--;
			//st->PrintAllScopeTable();
			fprintf(logout,"Total Lines: %d\n",line_count); 
			//fprintf(logout,"Total Errors: %d\n",error_count);
			//st->FreeSpace();
			return 0;
			}

%%

int yywrap(void)
{
	return 1;
}

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
extern int errorcount ;
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
				SymbolInfo *s=new  SymbolInfo(yytext,"int");
				s->Token="CONST_INT";
				s->ivalue = atoi(yytext);
				yylval = (YYSTYPE)s;
				return CONST_INT;
			}

{FLOAT_NUMBER}	{
				SymbolInfo *s=new  SymbolInfo(yytext,"float");
				s->Token="CONST_FLOAT";
				s->fvalue = atof(yytext);
				cout<<"CONST_FLOAT : "<<yytext<<" "<<s->fvalue<<endl;
				yylval = (YYSTYPE)s;
				return CONST_FLOAT;
			}

{IDENTIFIER}	{
				SymbolInfo *s=new  SymbolInfo(yytext,"");
				s->Token="ID";
				cout<<"Id = "<< s->getName()<<endl;
				yylval = (YYSTYPE)s;
				return ID;
			}

[+-]		{
			SymbolInfo *s= new  SymbolInfo(yytext,"");
			s->Token="ADDOP";
			yylval = (YYSTYPE)s;
			return ADDOP;
			}
[*/%]		{
			SymbolInfo *s= new  SymbolInfo(yytext,"");
			s->Token="MULOP";
			yylval = (YYSTYPE)s;
			return MULOP;
			}
"++"		{ return INCOP; }

"--"		{ return DECOP; }

"<"|"<="|">"|">="|"=="|"!="		{ 
			SymbolInfo *s= new  SymbolInfo(yytext,"");
			s->Token="RELOP";
			yylval = (YYSTYPE)s;
			return RELOP; }

"="		{ return ASSINOP; }

"&&"|"||"		{ 
			SymbolInfo *s= new  SymbolInfo(yytext,"");
			s->Token="LOGICOP";
			yylval = (YYSTYPE)s;
			return LOGICOP; 
		}

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
			//return SINGLECOM;
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
			//return MULTICOM;
			}
<MULTICOM><<EOF>> {
			temp+=yytext;
			fprintf(logout,"Error at line %d: Unterminated comment %s\n\n",line_count-templine,temp.c_str());
			//error_count++;
			temp="";
			templine=0;
			BEGIN INITIAL;
			//return MULTICOM;
			}
<MULTICOM>.    {
			temp+=yytext;
			}

{DECIMAL_POINT_ERROR} { 
//			BEGIN ERR;
			fprintf(logout,"Error at line %d: Too many decimal point %s\n\n",line_count,yytext);
			fprintf(error,"Error at line %d: Too many decimal point %s\n\n",line_count,yytext);
			errorcount++;
			}
{ILL_FORMATTED_NUMBER} {
//BEGIN ERR;
			fprintf(logout,"Error at line %d: Ill formed number %s\n\n",line_count,yytext);
			fprintf(error,"Error at line %d: Ill formed number %s\n\n",line_count,yytext);
			errorcount++;
			}
{NON_IDENTIFIER}  {
//BEGIN ERR;
			fprintf(logout,"Error at line %d: Invalid prefix on ID or invalid suffix on Number %s\n\n",line_count,yytext);
			fprintf(error,"Error at line %d: Invalid prefix on ID or invalid suffix on Number %s\n\n",line_count,yytext);
			errorcount++;
		}
{EMPTY_CHAR} {
//BEGIN ERR;
			fprintf(logout,"Error at line %d: Empty character constant error %s \n\n",line_count,yytext);
			fprintf(error,"Error at line %d: Empty character constant error %s \n\n",line_count,yytext);
			errorcount++;
			}
{UNTERMINATED_CHAR} {
//BEGIN ERR;
			fprintf(logout,"Error at line %d: Unterminated character %s\n\n",line_count,yytext);
			fprintf(error,"Error at line %d: Unterminated character %s\n\n",line_count,yytext);
			errorcount++;
			}
{UNRECOGNIZED_CHAR} {
//BEGIN ERR;
			fprintf(logout,"Error at line %d: Unrecognized character %s\n\n",line_count,yytext);
			fprintf(error,"Error at line %d: Unrecognized character %s\n\n",line_count,yytext);
			errorcount++;
			}
{MULTI_CHAR} {
//BEGIN ERR;
			fprintf(logout,"Error at line %d: Multi character constant error %s\n\n",line_count,yytext);
			fprintf(error,"Error at line %d: Multi character constant error %s\n\n",line_count,yytext);
			errorcount++;
			}
<<EOF>> 	{
			//st->FreeSpace();
			return 0;
			}

%%

int yywrap(void)
{
	return 1;
}

%{
#include<bits/stdc++.h>
//#include "SymbolTable.h"
#include "SymbolInfo.h"
#include "y.tab.h"
extern ofstream tout;

using namespace std;

extern YYSTYPE yylval;
//extern SymbolTable *table;
void yyerror(char *);

int linecount=1;


%}



digit [0-9]
letter [A-Za-z]
delim [ \t\r\f\v]
newline \n
ws [delim]+
id (_|{letter})(_|{letter}|{digit})*
integer {digit}+
number {digit}*(\.{digit}+)?(E[+-]?{digit}+)?
ADDOP [+-] 
MULOP [*/%]

%%

{delim}+	{}
{newline} {linecount++;}
"if" {return IF;}
"else" {return ELSE;}
"for" {return FOR;}
"while" {return WHILE;}
"int" {return INT;}
"float" {return FLOAT;}
"double" {return DOUBLE;}
"char" {return CHAR;}
"return" {return RETURN;}
"void" {return VOID;}
"main"	{return MAIN;}
"println"	{return PRINTLN;}

{ADDOP} { 
			SymbolInfo *s= new  SymbolInfo(yytext, (char *)"ADDOP");
			yylval = (YYSTYPE)s;
			return ADDOP;
		}



{MULOP}	{
			SymbolInfo *s= new  SymbolInfo(yytext, (char *)"MULOP");
			yylval = (YYSTYPE)s;
			return MULOP;
		}


"=" 	{return ASSIGNOP;}




">" |
"<" |
">=" |
"<=" |
"==" |
"!=" {
		SymbolInfo *s= new  SymbolInfo(yytext, (char *)"RELOP");
		yylval = (YYSTYPE)s;
		return RELOP;
	}

	
"&&"	|
"||"	{
			SymbolInfo *s= new  SymbolInfo(yytext, (char *)"LOGICOP");
			yylval = (YYSTYPE)s;
			return LOGICOP;
		}
"!"		{	return NOT; }


";" 	{return SEMICOLON;}
"," 	{return COMMA;}
"(" 	{return LPAREN;}
")" 	{return RPAREN;}
"{" 	{return LCURL;}
"}" 	{return RCURL;}
"[" 	{return LTHIRD;}
"]" 	{return RTHIRD;}
"++" 	{return INCOP;}
"--" 	{return DECOP;}



{integer}	{
				SymbolInfo *s= new  SymbolInfo(yytext, (char *)"CONST_INT");
				s->ivalue = atoi(yytext);
				yylval = (YYSTYPE)s;
				return CONST_INT;
			}
{number} 	{	
				SymbolInfo *s= new  SymbolInfo(yytext, (char *)"CONST_FLOAT");
				s->fvalue = atof(yytext);
				yylval = (YYSTYPE)s;
				return CONST_FLOAT; 
			}
\'[.]{1}\' {
				SymbolInfo *s= new  SymbolInfo(yytext, (char *)"CONST_CHAR");
				s->c = yytext[1];
				yylval = (YYSTYPE)s;
				return CONST_CHAR;
			}
			
\'\\[ntrbv0af]\' { 
				SymbolInfo *s= new  SymbolInfo(yytext, (char *)"CONST_CHAR"); //Do we really need to typecast
				
				s->c += yytext[1];
				s->c += yytext[2];
				if(yytext[2] == 'n'){
					s->c = '\n';
				}
				else if(yytext[2] == 'n'){
					s->c = '\n';
				}
				else if(yytext[2] == 't'){
					s->c = '\t';
				}
				else if(yytext[2] == 'r'){
					s->c = '\r';
				}
				else if(yytext[2] == 'b'){
					s->c = '\b';
				}
				else if(yytext[2] == 'v'){
					s->c = '\v';
				}
				else if(yytext[2] == '0'){
					s->c = '\0';
				}
				else if(yytext[2] == 'a'){
					s->c = '\a';
				}
				else if(yytext[2] == 'f'){
					s->c = '\f';
				}
				
				
				yylval = (YYSTYPE)s;
				return CONST_CHAR;
			}
			
{id} 		{	 
				SymbolInfo* s= new SymbolInfo(yytext, (char *)"ID");
				yylval = (YYSTYPE)s;	
				return ID;
			}


%%

int yywrap(void)
{
	return 1;
}



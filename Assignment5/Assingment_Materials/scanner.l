%option noyywrap

%{
#include <bits/stdc++.h>
#include "y.tab.h"

using namespace std;

extern YYSTYPE yylval;

void yyerror(char *);
%}

NEWLINE \n
WS [ \t]+
DIGIT [0-9]
LETTER [A-Za-z]
NUMBER {DIGIT}+
ID (_|{LETTER})(_|{LETTER}|{DIGIT})*

%%
{NEWLINE}    { return NEWLINE;}
{NUMBER}  {
  		strcpy(yylval.addr,yytext);
	    return NUMBER;
    }

{ID} {
		strcpy(yylval.addr,yytext);
		return ID;
    }

"+"       { return PLUS; }
"-"       { return MINUS; }
"/"       { return SLASH; }
"*"       { return ASTERISK; }
"("       { return LPAREN; }
")"       { return RPAREN; }

{WS} { /* No action and no return */}

%%

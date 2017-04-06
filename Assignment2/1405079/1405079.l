%option noyywrap
%x STRINGSTATE
%x SINGLECOM
%x MULTICOM
%{
#include<stdio.h>
#include<stdlib.h>
#include "symboltable.h"

int line_count=1;
int error_count=0;
bool prac=false;
int templine=0;

FILE *logout;
FILE *token;

string temp="";
string realstr="";
SymbolTable *st;
int arrchar[10][2]={{110,10},{116,9},{97,7},{98,8},{102,12},{48,0},{92,92},{114,13},{34,34},{118,11}};
%}
NEWLINE \n

WHITESPACE [ \t\f\r\v]+ 
LETTER [a-zA-Z]
DIGIT [0-9]
FLOAT_NUMBER [0-9]*([.][0-9]+)?(E[+-]?[0-9]+)?
CHARACTER '[A-Za-z0-9]'
CHARACTER_EX '\\[ntabfv0\\r"v]'
IDENTIFIER [A-Za-z_][A-Za-z0-9_]*


NON_IDENTIFIER [0-9]+[A-Za-z0-9_]+
DECIMAL_POINT_ERROR [0-9]*[.]([0-9]*[.]+[0-9]*)*
ILL_FORMATTED_NUMBER [0-9]*((E[+-]?[0-9]+)([.][0-9]+)*)(E[+-]?[0-9]+)?([.][0-9]+)*
EMPTY_CHAR ''
UNDETERMINED_CHAR '[^A-Za-z0-9'\n]+'
ILL_FORMATTED_CHAR '[A-Za-z0-9 ][A-Za-z0-9 ]+'
UNTERMINATED_CHAR '[A-Za-z0-9]*


%%

{WHITESPACE}    {}
{NEWLINE} {line_count++;}


"if"	{
			fprintf(token,"<IF> ");
			fprintf(logout,"Line no %d: TOKEN <IF> Lexeme %s found\n\n",line_count,yytext);
		}

"for"	{
			fprintf(token,"<FOR> ");
			fprintf(logout,"Line no %d: TOKEN <FOR> Lexeme %s found\n\n",line_count,yytext);
		}
"do"	{
			fprintf(token,"<DO> ");
			fprintf(logout,"Line no %d: TOKEN <DO> Lexeme %s found\n\n",line_count,yytext);
		}
"int"	{
			fprintf(token,"<INT> ");
			fprintf(logout,"Line no %d: TOKEN <INT> Lexeme %s found\n\n",line_count,yytext);
		}
"float"	{
			fprintf(token,"<FLOAT> ");
			fprintf(logout,"Line no %d: TOKEN <FLOAT> Lexeme %s found\n\n",line_count,yytext);

		}
"void"	{
			fprintf(token,"<VOID> ");
			fprintf(logout,"Line no %d: TOKEN <VOID> Lexeme %s found\n\n",line_count,yytext);
		}
"switch"	{
			fprintf(token,"<SWITCH> ");
			fprintf(logout,"Line no %d: TOKEN <SWITCH> Lexeme %s found\n\n",line_count,yytext);
		}
"default"	{
			fprintf(token,"<DEFAULT> ");
			fprintf(logout,"Line no %d: TOKEN <DEFAULT> Lexeme %s found\n\n",line_count,yytext);
		}

"else"	{
			fprintf(token,"<ELSE> ");
			fprintf(logout,"Line no %d: TOKEN <ELSE> Lexeme %s found\n\n",line_count,yytext);
		}
"while"	{
			fprintf(token,"<WHILE> ");
			fprintf(logout,"Line no %d: TOKEN <WHILE> Lexeme %s found\n\n",line_count,yytext);
		}
"break"	{
			fprintf(token,"<BREAK> ");
			fprintf(logout,"Line no %d: TOKEN <BREAK> Lexeme %s found\n\n",line_count,yytext);
		}
"char"	{
			fprintf(token,"<CHAR> ");
			fprintf(logout,"Line no %d: TOKEN <CHAR> Lexeme %s found\n\n",line_count,yytext);
		}
"double"	{
			fprintf(token,"<DOUBLE> ");
			fprintf(logout,"Line no %d: TOKEN <DOUBLE> Lexeme %s found\n\n",line_count,yytext);
		}
"return"	{
			fprintf(token,"<RETURN> ");
			fprintf(logout,"Line no %d: TOKEN <RETURN> Lexeme %s found\n\n",line_count,yytext);
		}
"case"	{
			fprintf(token,"<CASE> ");
			fprintf(logout,"Line no %d: TOKEN <CASE> Lexeme %s found\n\n",line_count,yytext);
		}
"continue"	{
			fprintf(token,"<CONTINUE> ");
			fprintf(logout,"Line no %d: TOKEN <CONTINUE> Lexeme %s found\n\n",line_count,yytext);
		}



{DIGIT}+ 	{
				fprintf(token,"<CONST_INT, %s> ",yytext);
				fprintf(logout,"Line no %d: TOKEN <CONST_INT> Lexeme %s found\n\n",line_count,yytext);
				st->Insert(yytext,"CONST_INT");
			}

{FLOAT_NUMBER}	{
				fprintf(token,"<CONST_FLOAT, %s> ",yytext);
				fprintf(logout,"Line no %d: TOKEN <CONST_FLOAT> Lexeme %s found\n\n",line_count,yytext);
				st->Insert(yytext,"CONST_FLOAT");
			}
{CHARACTER}	{
				fprintf(token,"<CHAR_CONST, %c> ",yytext[1]);
				fprintf(logout,"Line no %d: TOKEN <CHAR_CONST> Lexeme %s found\n\n",line_count,yytext);
				st->Insert(yytext,"CHAR_CONST");
			}
{CHARACTER_EX}	{

/*if(strcmp(yytext,"\'\t\'"))
{
    fprintf(token,"<CHAR_CONST, %c>",'\t');
}
else 
{
    fprintf(token,"<CHAR_CONST,%s>",yytext);
}*/
				for(int i=0;i<10;i++)
				{
				    if(yytext[2]==arrchar[i][0]){
					    fprintf(token,"<CHAR_CONST, %c> ",arrchar[i][1]);
					    break;
				    }
				}

				fprintf(logout,"Line no %d: TOKEN <CHAR_CONST> Lexeme %s found\n\n",line_count,yytext);
				st->Insert(yytext,"CHAR_CONST");
			}

{IDENTIFIER}	{
				fprintf(token,"<ID, %s> ",yytext);
				fprintf(logout,"Line no %d: TOKEN <ID> Lexeme %s found\n\n",line_count,yytext);
				st->Insert(yytext,"ID");
			}



[+-]		{
			fprintf(token,"<ADDOP, %s> ",yytext);
			fprintf(logout,"Line no %d: TOKEN <ADDOP> Lexeme %s found\n\n",line_count,yytext);
			}
[*/%]		{
			fprintf(token,"<MULOP, %s> ",yytext);
			fprintf(logout,"Line no %d: TOKEN <MULOP> Lexeme %s found\n\n",line_count,yytext);
			}
"++"|"--"		{
			fprintf(token,"<INCOP, %s> ",yytext);
			fprintf(logout,"Line no %d: TOKEN <INCOP> Lexeme %s found\n\n",line_count,yytext);
			}
"<"|"<="|">"|">="|"=="|"!="		{
			fprintf(token,"<RELOP, %s> ",yytext);
			fprintf(logout,"Line no %d: TOKEN <RELOP> Lexeme %s found\n\n",line_count,yytext);
			}
"="		{
			fprintf(token,"<ASSINOP, %s> ",yytext);
			fprintf(logout,"Line no %d: TOKEN <ASSINOP> Lexeme %s found\n\n",line_count,yytext);
			}
"&&"|"||"		{
			fprintf(token,"<LOGICOP, %s> ",yytext);
			fprintf(logout,"Line no %d: TOKEN <LOGICOP> Lexeme %s found\n\n",line_count,yytext);
			}

"!"		{
			fprintf(token,"<NOT, %s> ",yytext);
			fprintf(logout,"Line no %d: TOKEN <NOT> Lexeme %s found\n\n",line_count,yytext);
			}

"("		{
			fprintf(token,"<LPAREN, %s> ",yytext);
			fprintf(logout,"Line no %d: TOKEN <LPAREN> Lexeme %s found\n\n",line_count,yytext);
			}
")"		{
			fprintf(token,"<RPAREN, %s> ",yytext);
			fprintf(logout,"Line no %d: TOKEN <RPAREN> Lexeme %s found\n\n",line_count,yytext);
			}
"{"		{
			fprintf(token,"<LCURL, %s> ",yytext);
			fprintf(logout,"Line no %d: TOKEN <LCURL> Lexeme %s found\n\n",line_count,yytext);
			}
"}"		{
			fprintf(token,"<RCURL, %s> ",yytext);
			fprintf(logout,"Line no %d: TOKEN <RCURL> Lexeme %s found\n\n",line_count,yytext);
			}
"["		{
			fprintf(token,"<LTHIRD, %s> ",yytext);
			fprintf(logout,"Line no %d: TOKEN <LTHIRD> Lexeme %s found\n\n",line_count,yytext);
			}
"]"		{
			fprintf(token,"<RTHIRD, %s> ",yytext);
			fprintf(logout,"Line no %d: TOKEN <RTHIRD> Lexeme %s found\n\n",line_count,yytext);
			}
","		{
			fprintf(token,"<COMMA, %s> ",yytext);
			fprintf(logout,"Line no %d: TOKEN <COMMA> Lexeme %s found\n\n",line_count,yytext);
			}
";"		{
			fprintf(token,"<SEMICOLON, %s> ",yytext);
			fprintf(logout,"Line no %d: TOKEN <SEMICOLON> Lexeme %s found\n\n",line_count,yytext);
			}

\"      { 
			BEGIN STRINGSTATE;
			temp+="\"";
			realstr+="\"";
			if(prac)fprintf(logout,"In state #1 %s found\n\n",yytext);		
		}
		
<STRINGSTATE>\\$    {realstr+="\\";if(prac)fprintf(logout,"In state #3 %s found\n\n",yytext);		}
<STRINGSTATE>\"    {

			if(prac)fprintf(logout,"In state #100 %s found\n\n",temp.c_str());
			string tokenstr="";
			bool flag=true;
			for(int j=0;j<temp.size()-1;j++)
			{
				if(prac)cout<<temp[j]<<endl;
				if(temp[j]=='\\'){
					flag=false;
					for(int i=0;i<10;i++)
					{
					    if(temp[j+1]==arrchar[i][0]){
						    tokenstr+=arrchar[i][1];
						    flag=true;
						    if(j==temp.size()-3)tokenstr+=temp[temp.size()-1];
							j++;
						    break;
					    }
					}
					if(!flag)
					{
						temp+=yytext;realstr+=yytext;
									fprintf(logout,"Error at line %d: Undetermined string part \\%c at %s\n\n",line_count-templine,temp[j+1],realstr.c_str());
									error_count++;
									BEGIN INITIAL;
									realstr="";
									temp="";
									templine=0;
						break;
					}
				}
				else
				{
					tokenstr+=temp[j];
					if(j==temp.size()-2)tokenstr+=temp[j+1];
				}

			}
			if(flag){
		
						fprintf(token,"<STRING>, %s\"> ",tokenstr.c_str());
						fprintf(logout,"Line No. %d: Token <STRING> Lexeme %s\" found\n\n",line_count-templine,realstr.c_str());
						BEGIN INITIAL;
						temp="";
						templine=0;
						realstr="";
			}

			}
<STRINGSTATE>\"$  {

			if(prac)fprintf(logout,"In state #100 %s found\n\n",temp.c_str());
			string tokenstr="";
			bool flag=true;
			for(int j=0;j<temp.size()-1;j++)
			{
				if(prac)cout<<temp[j]<<endl;
				if(temp[j]=='\\'){
					flag=false;
					for(int i=0;i<10;i++)
					{
					    if(temp[j+1]==arrchar[i][0]){
						    tokenstr+=arrchar[i][1];
						    flag=true;
						    if(j==temp.size()-3)tokenstr+=temp[temp.size()-1];
							j++;
						    break;
					    }
					}
					if(!flag)
					{
						temp+=yytext;realstr+=yytext;
									fprintf(logout,"Error at line %d: Undetermined string part \\%c at %s\n\n",line_count-templine,temp[j+1],realstr.c_str());
									error_count++;
									BEGIN INITIAL;
									realstr="";
									temp="";
									templine=0;
						break;
					}
				}
				else
				{
					tokenstr+=temp[j];
					if(j==temp.size()-2)tokenstr+=temp[j+1];
				}

			}
			if(flag){
		
						fprintf(token,"<STRING>, %s\"> ",tokenstr.c_str());
						fprintf(logout,"Line No. %d: Token <STRING> Lexeme %s\" found\n\n",line_count-templine,realstr.c_str());
						BEGIN INITIAL;
						temp="";
						templine=0;
						realstr="";
			}

			}
<STRINGSTATE>.$ {
			if(prac)fprintf(logout,"In state #6 %s found\n\n",yytext);		
			temp+=yytext;realstr+=yytext;
			fprintf(logout,"Error at line %d: Unterminated string %s\n\n",line_count-templine,realstr.c_str());
			error_count++;
			BEGIN INITIAL;
			realstr="";
			temp="";
			templine=0;
			}
<STRINGSTATE><<EOF>> {
			if(prac)fprintf(logout,"In state #6 %s found\n\n",yytext);		
			temp+=yytext;realstr+=yytext;
			fprintf(logout,"Error at line %d: Unterminated string %s\n\n",line_count-templine,realstr.c_str());
			error_count++;
			BEGIN INITIAL;
			realstr="";
			temp="";
			templine=0;
			}
<STRINGSTATE>{NEWLINE}     {
				
			if(realstr[realstr.size()-1]=='\\'){
			if(prac)fprintf(logout,"In state #2 %s found\n\n",yytext);
			realstr+="\n";
			templine++;
}
else{
			temp+=yytext;
			realstr+=yytext;
			fprintf(logout,"Error at line %d: Unterminated string %s\n\n",line_count-templine,realstr.c_str());
			error_count++;
			BEGIN INITIAL;
			temp="";
			templine=0;
			realstr="";
}
line_count++;
}
<STRINGSTATE>\\\\ {
			temp+=yytext;realstr+=yytext;
			//fprintf(token,"%s",yytext);			
			if(prac)fprintf(logout,"In state #7 %s found\n\n",yytext);
} 
<STRINGSTATE>\\\"    {
			temp+=yytext;realstr+=yytext;
			//fprintf(token,"%s",yytext);			
			if(prac)fprintf(logout,"In state #7 %s found\n\n",yytext);		
			}
<STRINGSTATE>.    {
			temp+=yytext;realstr+=yytext;
			//fprintf(token,"%s",yytext);			
			if(prac)fprintf(logout,"In state #7 %s found\n\n",yytext);		
			}
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
			}
<MULTICOM><<EOF>> {
			temp+=yytext;
			fprintf(logout,"Error at line %d: Unterminated comment %s\n\n",line_count-templine,temp.c_str());
			error_count++;
			BEGIN INITIAL;
			temp="";
			templine=0;
			}
<MULTICOM>.    {
			temp+=yytext;
			}

{DECIMAL_POINT_ERROR} {
			fprintf(logout,"Error at line %d: Too many decimal point %s\n\n",line_count,yytext);
			error_count++;
			}
{ILL_FORMATTED_NUMBER} {
			fprintf(logout,"Error at line %d: Ill formed number %s\n\n",line_count,yytext);
			error_count++;
			}
{NON_IDENTIFIER}  {
			fprintf(logout,"Error at line %d: Invalid prefix on ID or invalid suffix on Number %s\n\n",line_count,yytext);
			error_count++;
		}
{EMPTY_CHAR} {
			fprintf(logout,"Error at line %d: Empty character constant error %s \n\n",line_count,yytext);
			error_count++;
			}
{UNTERMINATED_CHAR}|'\\'|'  {
			fprintf(logout,"Error at line %d: Unterminated character %s\n\n",line_count,yytext);
			error_count++;
			}
{UNDETERMINED_CHAR} {
			fprintf(logout,"Error at line %d: Unrecognized character %s\n\n",line_count,yytext);
			error_count++;
			}
{ILL_FORMATTED_CHAR} {
			fprintf(logout,"Error at line %d: Multi character constant error %s\n\n",line_count,yytext);
			error_count++;
			}



<<EOF>> 	{
			//line_count--;
			st->PrintAllScopeTable();
			fprintf(logout,"Total Lines: %d\n",line_count); 
			fprintf(logout,"Total Errors: %d\n",error_count);
			st->FreeSpace();
			return 0;
			}

%%

int main(int argc,char *argv[]){
	
	if(argc!=2){
		printf("Please provide input file name and try again\n");
		return 0;
	}
	
	FILE *fin=fopen(argv[1],"r");
	if(fin==NULL){
		printf("Cannot open specified file\n");
		return 0;
	}
	
	logout= fopen("log.txt","w");
	token= fopen("token.txt","w");
	st=new SymbolTable(7,1);

	yyin= fin;
	yylex();
	fclose(yyin);
	fclose(token);
	fclose(logout);
	return 0;
}

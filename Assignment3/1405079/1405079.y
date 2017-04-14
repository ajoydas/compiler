
%{
#include<bits/stdc++.h>
#include "SymbolTable.h"
#define YYSTYPE SymbolInfo* 
using namespace std;

int yyparse(void);
int yylex(void);
extern FILE *yyin;

FILE *logout;
FILE *error;
FILE *symtable;

SymbolTable* table = new SymbolTable(7,1);

int errorcount = 0;
extern int line_count;

string type;
vector<SymbolInfo> params;

void yyerror(string s){
	errorcount++;
fprintf(logout,"Line No. %d: Error Number %d %s program\n\n",line_count,errorcount,s.c_str());
}

%}

%token IF FOR DO INT FLOAT VOID SWITCH DEFAULT ELSE  WHILE BREAK RETURN CASE CONTINUE PRINTLN CONST_INT CONST_FLOAT CONST_CHAR ID ADDOP MULOP INCOP DECOP RELOP ASSINOP LOGICOP NOT LPAREN RPAREN LCURL RCURL LTHIRD RTHIRD COMMA SEMICOLON SINGLECOM MULTICOM 
 

%%

start : program
	{
		fprintf(logout,"Line No. %d: start : program\n\n",line_count);
	}
	;

program : program unit
	{
		fprintf(logout,"Line No. %d: program : program unit\n\n",line_count);
	} 
	| 
	unit
	{
		fprintf(logout,"Line No. %d: program : unit\n\n",line_count);
	}
	;
	
unit :
     	func_declaration
     	{ 
/*var_declaration
		{
			fprintf(logout,"Line No. %d: unit : var_declaration\n\n",line_count);
		}
     	| */
			fprintf(logout,"Line No. %d: unit : func_declaration\n\n",line_count);

     	}
     	| 
     	func_definition
     	{
			fprintf(logout,"Line No. %d: unit : func_definition\n\n",line_count);
     	}
     	;
     
func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON
			{
				fprintf(logout,"Line No. %d: func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n\n",line_count);

//insert the function
if(table->Lookup($2->getName())==NULL)
{
table->Insert($2->getName(),"function");
SymbolInfo *s=table->Lookup($2->getName());
s->fp=new Function();
s->fp->retype= type;
s->fp->params=params;
cout<<params.size();
}
else
{
fprintf(error,"Line No. %d: Multiple declaration Function %s\n\n",line_count,$2->getName().c_str());
}

			}
		 	;
		 
func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement
			{


			}
 		 	;
 		 
parameter_list  : parameter_list COMMA type_specifier ID
{
fprintf(logout,"Line No. %d: parameter_list  : parameter_list COMMA type_specifier ID\n\n",line_count);
SymbolInfo sym($4->getName(),type);
params.push_back(sym );

}

		| parameter_list COMMA type_specifier	 
{
fprintf(logout,"Line No. %d: parameter_list  : parameter_list COMMA type_specifier\n\n",line_count);
}

 		| type_specifier ID
{
fprintf(logout,"Line No. %d: parameter_list  : type_specifier ID\n\n",line_count);
SymbolInfo sym($2->getName(),type);
params.push_back(sym );

}

 		| type_specifier
{
 fprintf(logout,"Line No. %d: parameter_list  : type_specifier\n\n",line_count);
}

		|
{
fprintf(logout,"Line No. %d: parameter_list  : empty\n\n",line_count);
}
 		;


compound_statement : LCURL{table->EnterScope();} statements RCURL { fprintf(logout,"Line No. %d: program : unit\n\n",line_count); }
		   | LCURL RCURL { fprintf(logout,"Line No. %d: program : unit\n\n",line_count); }
		   ;

			 


type_specifier	: INT  { fprintf(logout,"Line No. %d: type_specifier : INT \n\n",line_count); type="int"; }
		| FLOAT { fprintf(logout,"Line No. %d: type_specifier : FLOAT\n\n",line_count); type="float"; }
		| VOID { fprintf(logout,"Line No. %d: type_specifier : VOID\n\n",line_count); type="void"; }
		;
		
statements: {}


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
	error= fopen("error.txt","w");
	symtable= fopen("symtable.txt","w");

	yyin= fin;
	yyparse();
	fclose(yyin);
	fclose(logout);
	fclose(error);
	fclose(symtable);
	return 0;
}


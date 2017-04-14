
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
	
unit :var_declaration
		{
			fprintf(logout,"Line No. %d: unit : var_declaration\n\n",line_count);
		}
     	|
     	func_declaration
     	{ 
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
				fprintf(logout,"Line No. %d: program : unit\n\n",line_count);
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

			 
var_declaration	: type_specifier declaration_list SEMICOLON { fprintf(logout,"Line No. %d: program : unit\n\n",linecount); }

type_specifier	: INT  { fprintf(logout,"Line No. %d: type_specifier : INT \n\n",line_count); type="int"; }
		| FLOAT { fprintf(logout,"Line No. %d: type_specifier : FLOAT\n\n",line_count); type="float"; }
		| VOID { fprintf(logout,"Line No. %d: type_specifier : VOID\n\n",line_count); type="void"; }
		;
		

declaration_list : declaration_list COMMA ID  { 
				fprintf(logout,"Line No. %d: program : unit\n\n",linecount);
				fout<<$3->Name<<endl;
				if(type == "int"){
					SymbolInfo* s = new SymbolInfo($3->Name, "int");
					s->Token = "ID";
					if(table->insert(s) == -1){
						yyerror("Multple declaration! ");
					}
				}
				if(type == "char"){
					SymbolInfo* s = new SymbolInfo($3->Name, "int");
					s->Token = "ID";
					if(table->insert(s) == -1){
						yyerror("Multple declaration! ");
					}
				}
				if(type == "float"){
					SymbolInfo* s = new SymbolInfo($3->Name, "int");
					s->Token = "ID";
					if(table->insert(s) == -1){
						yyerror("Multple declaration! ");
					}
				}
				
			}
		 | declaration_list COMMA ID LTHIRD CONST_INT RTHIRD { 
				fprintf(logout,"Line No. %d: program : unit\n\n",linecount);
				fout<<$3->Name<<endl;
				if(type == "int"){
					SymbolInfo* s = new SymbolInfo($3->Name, "int");
					s->Token = "ID";
					s->arraysize = $5->ivalue;
					if(table->insert(s) == -1){
						yyerror("Multple declaration! ");
					}
					
				}
				if(type == "char"){
					SymbolInfo* s = new SymbolInfo($3->Name, "int");
					s->arraysize = $5->ivalue;
					if(table->insert(s) == -1){
						yyerror("Multple declaration! ");
					}
					
				}
				if(type == "float"){
					SymbolInfo* s = new SymbolInfo($3->Name, "int");
					s->Token = "ID";
					s->arraysize = $5->ivalue;
					if(table->insert(s) == -1){
						yyerror("Multple declaration! ");
					}
				}
			}
		 | ID  {
				fprintf(logout,"Line No. %d: program : unit\n\n",linecount);
				fout<<$1->Name<<endl;
				if(type == "int"){
					SymbolInfo* s = new SymbolInfo($1->Name, "int");
					s->Token = "ID";
					if(table->insert(s) == -1){
						yyerror("Multple declaration! ");
					}
				}
				if(type == "char"){
					SymbolInfo* s = new SymbolInfo($1->Name, "char");
					s->Token = "ID";
					if(table->insert(s) == -1){
						yyerror("Multple declaration! ");
					}
				}
				if(type == "float"){
					SymbolInfo* s = new SymbolInfo($1->Name, "float");
					s->Token = "ID";
					if(table->insert(s) == -1){
						yyerror("Multple declaration! ");
					}
				}
			}
		 | ID LTHIRD CONST_INT RTHIRD  { 
				fprintf(logout,"Line No. %d: program : unit\n\n",linecount);
				fout<<$1->Name<<endl;
				
				if(type == "int"){
					SymbolInfo* s = new SymbolInfo($1->Name, "int");
					s->Token = "ID";
					s->arraysize = $3->ivalue;
					if(table->insert(s) == -1){
						yyerror("Multple declaration! ");
					}
				}
				if(type == "char"){
					SymbolInfo* s = new SymbolInfo($1->Name, "int");
					s->Token = "ID";
					s->arraysize = $3->ivalue;
					if(table->insert(s) == -1){
						yyerror("Multple declaration! ");
					}
				}
				if(type == "float"){
					SymbolInfo* s = new SymbolInfo($1->Name, "int");
					s->Token = "ID";
					s->arraysize = $3->ivalue;
					if(table->insert(s) == -1){
						yyerror("Multple declaration! ");
					}
				}
			}
		 ;

statements : statement  { fprintf(logout,"Line No. %d: program : unit\n\n",linecount); }
	   | statements statement  { fprintf(logout,"Line No. %d: program : unit\n\n",linecount); }
	   ;


statement  : var_declaration { 
fprintf(logout,"Line No. %d: program : unit\n\n",linecount);
}
	   | expression_statement  {fprintf(logout,"Line No. %d: program : unit\n\n",linecount); }
	   | compound_statement  { fprintf(logout,"Line No. %d: program : unit\n\n",linecount); }
	   | FOR LPAREN expression_statement expression_statement expression RPAREN statement  { fprintf(logout,"Line No. %d: program : unit\n\n",linecount); }
	   | IF LPAREN expression RPAREN statement { fprintf(logout,"Line No. %d: program : unit\n\n",linecount); }
	   | IF LPAREN expression RPAREN statement ELSE statement { fprintf(logout,"Line No. %d: program : unit\n\n",linecount); }
	   | WHILE LPAREN expression RPAREN statement  { fprintf(logout,"Line No. %d: program : unit\n\n",linecount); }
	   | PRINTLN LPAREN ID RPAREN SEMICOLON  { fprintf(logout,"Line No. %d: program : unit\n\n",linecount); }
	   | RETURN expression SEMICOLON  { fprintf(logout,"Line No. %d: program : unit\n\n",linecount); }
	   ;
		
expression_statement	: SEMICOLON		 { fprintf(logout,"Line No. %d: program : unit\n\n",linecount); }	
			| expression SEMICOLON  { fprintf(logout,"Line No. %d: program : unit\n\n",linecount); }
//			;
						
variable : ID	{ 
			fprintf(logout,"Line No. %d: program : unit\n\n",linecount);
			SymbolInfo* temp = table->searchTable($1->Name);
			if (temp == 0){
				yyerror("Undeclared variable! ");
			}
			else $$ = temp;
		}
		| ID LTHIRD expression RTHIRD  {
			fprintf(logout,"Line No. %d: program : unit\n\n",linecount);
			fout<<$1->Name<<endl;
			SymbolInfo* temp = table->searchTable($1->Name);
			if (temp == 0){
				yyerror("Undeclared variable! ");
			}
			else{
				fout<<"Array index: "<<$3->ivalue<<endl;
				if(temp != 0){
					if($3->ivalue >= temp->arraysize){
						yyerror("Array size overbound\n");
					}
					else {
						$$ = temp->array[$3->ivalue];
						fout<<"Array index insert: "<<$$->ivalue<<endl;
					}
				}
			}
		}
	 ;
			
expression : logic_expression {
			fprintf(logout,"Line No. %d: program : unit\n\n",linecount);
			$$ = $1;
		}
	    | variable ASSINOP logic_expression 	 { 
			fprintf(logout,"Line No. %d: program : unit\n\n",linecount);
			//Print the symboltable here
			
			cout<<$3->ivalue;
			if($1->datatype == "int"){
				if($3->datatype == "int"){
					$1->ivalue = $3->ivalue;
				}
				if($3->datatype == "float"){
					$1->ivalue = $3->fvalue;
				}
				if($3->datatype == "char"){
					$1->ivalue = $3->c;
				}
			}
			else if($1->datatype == "float"){
				if($3->datatype == "int"){
					$1->fvalue = $3->ivalue;
				}
				if($3->datatype == "float"){
					$1->fvalue = $3->fvalue;
				}
				if($3->datatype == "char"){
					$1->fvalue = $3->c;
				}
			}
			else if($1->datatype == "char"){
				if($3->datatype == "int"){
					$1->c = $3->ivalue;
				}
				if($3->datatype == "float"){
					$1->c = $3->fvalue;
				}
				if($3->datatype == "char"){
					$1->c = $3->c;
				}
			}
			$$ = $1;
			table->printTable(fout);
		}
	   ;
			
logic_expression : rel_expression 	 { 
			fprintf(logout,"Line No. %d: program : unit\n\n",linecount);
			$$ = $1;
		}
		| rel_expression LOGICOP rel_expression 	 { 
			fprintf(logout,"Line No. %d: program : unit\n\n",linecount);
			SymbolInfo* s = new SymbolInfo();
			s->datatype = "int";
			
			float f1, f2;
			if($1->datatype == "int"){
				f1 = $1->ivalue;
			}
			else if($1->datatype == "float"){
				f1 = $1->fvalue;
			}
			else if($1->datatype == "char"){
				f1 = $1->c;
			}
			
			if($3->datatype == "int"){
				f2 = $3->ivalue;
			}
			else if($3->datatype == "float"){
				f2 = $3->fvalue;
			}
			else if($3->datatype == "char"){
				f2 = $3->c;
			}
			
			if($2->Name == "&&"){
				s->ivalue = f1&&f2;
			}
			else if ($2->Name == "||"){
				s->ivalue = f1||f2;
			}
			$$ = s;
		}
		;
			
rel_expression	: simple_expression  { 
			ffprintf(logout,"Line No. %d: program : unit\n\n",linecount);
			$$ = $1;
		}
		| simple_expression RELOP simple_expression	 { 
			fprintf(logout,"Line No. %d: program : unit\n\n",linecount);
			SymbolInfo* s = new SymbolInfo();
			s->datatype = "int";
			if($2->Name == "=="){
				if($1 == $2){
					s->ivalue = 1;
				}
				else {
					s->ivalue = 0;
				}
			}
			else if($2->Name == "!="){
				if($1 != $2){
					s->ivalue = 1;
				}
				else {
					s->ivalue = 0;
				}
			}
			else if($2->Name == ">"){
				if($1 > $2){
					s->ivalue = 1;
				}
				else {
					s->ivalue = 0;
				}
			}
			else if($2->Name == "<"){
				if($1 < $2){
					s->ivalue = 1;
				}
				else {
					s->ivalue = 0;
				}
			}
			else if($2->Name == ">="){
				if($1 >= $2){
					s->ivalue = 1;
				}
				else {
					s->ivalue = 0;
				}
			}
			else if($2->Name == "<="){
				if($1 <= $2){
					s->ivalue = 1;
				}
				else {
					s->ivalue = 0;
				}
			}
			else fout<<"Relational operator error"<<endl;
			$$ = s;
		}
		;
				
simple_expression : term  { 
			fprintf(logout,"Line No. %d: program : unit\n\n",linecount);
			$$ = $1;
		}
		| simple_expression ADDOP term  { 
			fprintf(logout,"Line No. %d: program : unit\n\n",linecount);
			SymbolInfo* s = new SymbolInfo();
			if($2->Name == "+"){
				if($1->datatype == "int" && $3->datatype == "int"){
					s->ivalue = $1->ivalue + $3->ivalue;
					s->datatype = "int";
					$$ = s;
				}
				else if($1->datatype == "int" && $3->datatype == "float"){
					s->fvalue = $1->ivalue + $3->fvalue;
					s->datatype = "float";
					$$ = s;
				}
				else if($1->datatype == "float" && $3->datatype == "int"){
					s->fvalue = $1->fvalue + $3->ivalue;
					s->datatype = "float";
					$$ = s;
				}
				else if($1->datatype == "float" && $3->datatype == "float"){
					s->fvalue = $1->fvalue + $3->fvalue;
					s->datatype = "float";
					$$ = s;
				}
				else if($1->datatype == "char" && $3->datatype == "char"){
					s->ivalue = $1->c + $3->c;
					s->datatype = "int";
					$$ = s;
				}
				else if($1->datatype == "char" && $3->datatype == "int"){
					s->ivalue = $1->c + $3->ivalue;
					s->datatype = "int";
					$$ = s;
				}
				else if($1->datatype == "int" && $3->datatype == "char"){
					s->ivalue = $1->ivalue + $3->c;
					s->datatype = "int";
					$$ = s;
				}
				else if($1->datatype == "char" && $3->datatype == "float"){
					s->fvalue = $1->c + $3->fvalue;
					s->datatype = "float";
					$$ = s;
				}
				else if($1->datatype == "float" && $3->datatype == "char"){
					s->fvalue = $1->fvalue + $3->c;
					s->datatype = "float";
					$$ = s;
				}
				else {
					fout<<"Incompatible addition"<<endl;
				}
				
			}
			else if($2->Name == "-"){
				if($1->datatype == "int" && $3->datatype == "int"){
					s->ivalue = $1->ivalue - $3->ivalue;
					s->datatype = "int";
					$$ = s;
				}
				else if($1->datatype == "int" && $3->datatype == "float"){
					s->fvalue = $1->ivalue - $3->fvalue;
					s->datatype = "float";
					$$ = s;
				}
				else if($1->datatype == "float" && $3->datatype == "int"){
					s->fvalue = $1->fvalue - $3->ivalue;
					s->datatype = "float";
					$$ = s;
				}
				else if($1->datatype == "float" && $3->datatype == "float"){
					s->fvalue = $1->fvalue - $3->fvalue;
					s->datatype = "float";
					$$ = s;
				}
				else if($1->datatype == "char" && $3->datatype == "char"){
					s->ivalue = $1->c - $3->c;
					s->datatype = "int";
					$$ = s;
				}
				else if($1->datatype == "char" && $3->datatype == "int"){
					s->ivalue = $1->c - $3->ivalue;
					s->datatype = "int";
					$$ = s;
				}
				else if($1->datatype == "int" && $3->datatype == "char"){
					s->ivalue = $1->ivalue - $3->c;
					s->datatype = "int";
					$$ = s;
				}
				else if($1->datatype == "char" && $3->datatype == "float"){
					s->fvalue = $1->c - $3->fvalue;
					s->datatype = "float";
					$$ = s;
				}
				else if($1->datatype == "float" && $3->datatype == "char"){
					s->fvalue = $1->fvalue - $3->c;
					s->datatype = "float";
					$$ = s;
				}
				else {
					fout<<"Incompatible addition"<<endl;
				}
			}
		}
		;
					
term :	unary_expression { 
			fprintf(logout,"Line No. %d: program : unit\n\n",linecount);
			$$ = $1;
		}
     |  term MULOP unary_expression { 
			fprintf(logout,"Line No. %d: program : unit\n\n",linecount);
						SymbolInfo* s = new SymbolInfo();
			if($2->Name == "*"){
				if($1->datatype == "int" && $3->datatype == "int"){
					s->ivalue = $1->ivalue * $3->ivalue;
					s->datatype = "int";
					$$ = s;
				}
				else if($1->datatype == "int" && $3->datatype == "float"){
					s->fvalue = $1->ivalue * $3->fvalue;
					s->datatype = "float";
					$$ = s;
				}
				else if($1->datatype == "float" && $3->datatype == "int"){
					s->fvalue = $1->fvalue * $3->ivalue;
					s->datatype = "float";
					$$ = s;
				}
				else if($1->datatype == "float" && $3->datatype == "float"){
					s->fvalue = $1->fvalue * $3->fvalue;
					s->datatype = "float";
					$$ = s;
				}
				else if($1->datatype == "char" && $3->datatype == "char"){
					s->ivalue = $1->c * $3->c;
					s->datatype = "int";
					$$ = s;
				}
				else if($1->datatype == "char" && $3->datatype == "int"){
					s->ivalue = $1->c * $3->ivalue;
					s->datatype = "int";
					$$ = s;
				}
				else if($1->datatype == "int" && $3->datatype == "char"){
					s->ivalue = $1->ivalue * $3->c;
					s->datatype = "int";
					$$ = s;
				}
				else if($1->datatype == "char" && $3->datatype == "float"){
					s->fvalue = $1->c * $3->fvalue;
					s->datatype = "float";
					$$ = s;
				}
				else if($1->datatype == "float" && $3->datatype == "char"){
					s->fvalue = $1->fvalue * $3->c;
					s->datatype = "float";
					$$ = s;
				}
				else {
					fout<<"Incompatible Multiplication"<<endl;
				}
				
			}
						else if($2->Name == "/"){
				if($1->datatype == "int" && $3->datatype == "int"){
					s->ivalue = $1->ivalue / $3->ivalue;
					s->datatype = "float";
					$$ = s;
				}
				else if($1->datatype == "int" && $3->datatype == "float"){
					s->fvalue = $1->ivalue / $3->fvalue;
					s->datatype = "float";
					$$ = s;
				}
				else if($1->datatype == "float" && $3->datatype == "int"){
					s->fvalue = $1->fvalue / $3->ivalue;
					s->datatype = "float";
					$$ = s;
				}
				else if($1->datatype == "float" && $3->datatype == "float"){
					s->fvalue = $1->fvalue / $3->fvalue;
					s->datatype = "float";
					$$ = s;
				}
				else if($1->datatype == "char" && $3->datatype == "char"){
					s->ivalue = $1->c / $3->c;
					s->datatype = "float";
					$$ = s;
				}
				else if($1->datatype == "char" && $3->datatype == "int"){
					s->ivalue = $1->c / $3->ivalue;
					s->datatype = "float";
					$$ = s;
				}
				else if($1->datatype == "int" && $3->datatype == "char"){
					s->ivalue = $1->ivalue / $3->c;
					s->datatype = "float";
					$$ = s;
				}
				else if($1->datatype == "char" && $3->datatype == "float"){
					s->fvalue = $1->c / $3->fvalue;
					s->datatype = "float";
					$$ = s;
				}
				else if($1->datatype == "float" && $3->datatype == "char"){
					s->fvalue = $1->fvalue / $3->c;
					s->datatype = "float";
					$$ = s;
				}
				else {
					fout<<"Incompatible Division"<<endl;
				}
				
			}
			//mod
			else if($2->Name == "%"){
				if($1->datatype == "int" && $3->datatype == "int"){
					s->ivalue = $1->ivalue % $3->ivalue;
					s->datatype = "int";
					$$ = s;
				}
				else if($1->datatype == "int" && $3->datatype == "float"){
					fout<<"Warning! Cannot take mod of float or with a float"<<endl;
				}
				else if($1->datatype == "float" && $3->datatype == "int"){
					fout<<"Warning! Cannot take mod of float or with a float"<<endl;
				}
				else if($1->datatype == "float" && $3->datatype == "float"){
					fout<<"Warning! Cannot take mod of float or with a float"<<endl;
				}
				else if($1->datatype == "char" && $3->datatype == "char"){
					s->ivalue = $1->c % $3->c;
					s->datatype = "int";
					$$ = s;
				}
				else if($1->datatype == "char" && $3->datatype == "int"){
					s->ivalue = $1->c % $3->ivalue;
					s->datatype = "int";
					$$ = s;
				}
				else if($1->datatype == "int" && $3->datatype == "char"){
					s->ivalue = $1->ivalue % $3->c;
					s->datatype = "int";
					$$ = s;
				}
				else if($1->datatype == "char" && $3->datatype == "float"){
					fout<<"Warning! Cannot take mod of float or with a float"<<endl;
				}
				else if($1->datatype == "float" && $3->datatype == "char"){
					fout<<"Warning! Cannot take mod of float or with a float"<<endl;
				}
				else {
					fout<<"Incompatible Modulation"<<endl;
				}
				
			}
			
		}
     ;

unary_expression : ADDOP unary_expression   { 
				fprintf(logout,"Line No. %d: program : unit\n\n",linecount);
				if($2->Name == "+"){
					$$ = $2;
				}
				else if($2->Name == "-"){
					if(type == "int"){
						$$->ivalue = $2->ivalue * -1;
					}
					else if(type == "char"){
						$$->c = $2->c * -1; //some cases are unhandled
					}
					else if(type == "float"){
						$$->fvalue = $2->fvalue * -1;
					}
				}
			}
		 | NOT unary_expression  { 
				fprintf(logout,"Line No. %d: program : unit\n\n",linecount);
				SymbolInfo* temp = new SymbolInfo();
				if(type == "int"){
					if($2->ivalue) {
						temp->ivalue = 0;
					}
					else{
						temp->ivalue = 1;
					}
				}
				else if(type == "char"){
					if($2->c) {
						temp->ivalue = 0;
					}
					else{
						temp->ivalue = 1;
					}
				}
				else if(type == "float"){
					if($2->fvalue) {
						temp->ivalue = 0;
					}
					else{
						temp->ivalue = 1;
					}
				}
				$$ = temp;
			}
		 | factor  { 
				fprintf(logout,"Line No. %d: program : unit\n\n",linecount);
				$$ = $1;
			}
		 ;
	
factor	: variable  { 
			fprintf(logout,"Line No. %d: program : unit\n\n",linecount);
			$$=$1;
		}
	| ID LPAREN argument_list RPAREN { //ajoy have to do
fprintf(logout,"Line No. %d: program : unit\n\n",linecount);
	}
	| LPAREN expression RPAREN  { 
			fprintf(logout,"Line No. %d: program : unit\n\n",linecount);
			$$ = $2;
		}
	| CONST_INT  { 
			fprintf(logout,"Line No. %d: program : unit\n\n",linecount);
			fout<<$1->ivalue<<endl;
			$$ = $1;
		}
	| CONST_FLOAT { 
			fprintf(logout,"Line No. %d: program : unit\n\n",linecount);
			fout<<$1->fvalue<<endl;
			$$ = $1;
		}
	| CONST_CHAR { 
			fprintf(logout,"Line No. %d: program : unit\n\n",linecount);
			fout<<$1->c<<endl;
			$$ = $1;
		}
	| variable INCOP  {  //Ajoy Have to edit
			fprintf(logout,"Line No. %d: program : unit\n\n",linecount);
			if(type == "int"){
				$1->ivalue++;
			}
			//elseif(type == "char" && ){
			//	$1->c
			//}
		}
	| variable DECOP {  //Ajoy Have to edit
			fprintf(logout,"Line No. %d: program : unit\n\n",linecount);
			if(type == "int"){
				$1->ivalue--;
			}
		}
	;

argument_list : argument_list COMMA logic_expression
{
fprintf(logout,"Line No. %d: program : unit\n\n",linecount);
}
	      | logic_expression
{
fprintf(logout,"Line No. %d: program : unit\n\n",linecount);
}
	      |
{
fprintf(logout,"Line No. %d: program : unit\n\n",linecount);
}
	      ;
 


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


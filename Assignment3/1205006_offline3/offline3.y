
%{
#include<bits/stdc++.h>
//#include "SymbolInfo.h"
#include "SymbolTable.h"
using namespace std;

#define YYSTYPE SymbolInfo*      /* yyparse() stack type */

ofstream fout("outputfile.txt");

extern SymbolTable* table = new SymbolTable(13);
int errorcount = 0;
extern int linecount;


string type;

void yyerror(string s){
	errorcount++;
	fout<<"Error Number "<<errorcount<<" "<<s<<" at line: "<<linecount;
	;
}

int yylex(void);

%}

%token IF ELSE FOR WHILE INT FLOAT DOUBLE CHAR RETURN VOID MAIN PRINTLN ADDOP MULOP ASSIGNOP RELOP LOGICOP SEMICOLON COMMA LPAREN RPAREN LCURL RCURL LTHIRD RTHIRD INCOP DECOP CONST_INT CONST_FLOAT CONST_CHAR ID NOT


%%
Program : INT MAIN LPAREN RPAREN compound_statement { fout<<"Program : INT MAIN LPAREN RPAREN compound_statement"<<endl;}
	;


compound_statement : LCURL var_declaration statements RCURL { fout<<"compound_statement : LCURL var_declaration statements RCURL"<<endl;}
		   | LCURL statements RCURL LCURL { fout<<"compound_statement : LCURL statements RCURL LCURL "<<endl; }
		   | LCURL RCURL { fout<<"compound_statement : LCURL RCURL "<<endl; }
		   ;

			 
var_declaration	: type_specifier declaration_list SEMICOLON { fout<<"var_declaration	: type_specifier declaration_list SEMICOLON "<<endl; }
		|  var_declaration type_specifier declaration_list SEMICOLON { fout<<"var_declaration	: var_declaration type_specifier declaration_list SEMICOLON"<<endl; }
		;

type_specifier	: INT  { fout<<"type_specifier	: INT  "<<endl; type = "int"; }
		| FLOAT { fout<<"type_specifier	: FLOAT"<<endl; type = "float"; }
		| CHAR { fout<<"type_specifier	: CHAR"<<endl; type = "char"; }
		;
		
declaration_list : declaration_list COMMA ID  { 
				fout<<"declaration_list : declaration_list COMMA ID"<<endl;
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
				fout<<"declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD"<<endl;
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
				fout<<"declaration_list : ID"<<endl; 
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
				fout<<"declaration_list : ID LTHIRD CONST_INT RTHIRD"<<endl;
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

statements : statement  { fout<<"statements : statement"<<endl; }
	   | statements statement  { fout<<"statements : statements statement"<<endl; }
	   ;


statement  : expression_statement  { fout<<"statement  : expression_statement"<<endl; }
	   | compound_statement  { fout<<"statement  : compound_statement"<<endl; }
	   | FOR LPAREN expression_statement expression_statement expression RPAREN statement  { fout<<"statement  : FOR LPAREN expression_statement expression_statement expression RPAREN statement"<<endl; }
	   | IF LPAREN expression RPAREN statement { fout<<"statement  : IF LPAREN expression RPAREN statement"<<endl; }
	   | IF LPAREN expression RPAREN statement ELSE statement { fout<<"statement  : IF LPAREN expression RPAREN statement ELSE statement"<<endl; }
	   | WHILE LPAREN expression RPAREN statement  { fout<<"statement  : WHILE LPAREN expression RPAREN statement "<<endl; }
	   | PRINTLN LPAREN ID RPAREN SEMICOLON  { fout<<"statement  : PRINTLN LPAREN ID RPAREN SEMICOLON "<<endl; }
	   | RETURN expression SEMICOLON  { fout<<"statement  : RETURN expression SEMICOLON "<<endl; }
	   ;
		
expression_statement	: SEMICOLON		 { fout<<"expression_statement	: SEMICOLON"<<endl; }	
			| expression SEMICOLON  { fout<<"expression_statement	: expression SEMICOLON"<<endl; }
//			;
						
variable : ID	{ 
			fout<<"variable : ID"<<endl;
			SymbolInfo* temp = table->searchTable($1->Name);
			if (temp == 0){
				yyerror("Undeclared variable! ");
			}
			else $$ = temp;
		}
		| ID LTHIRD expression RTHIRD  {
			fout<<"variable : ID LTHIRD expression RTHIRD "<<endl;
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
			fout<<"expression : logic_expression"<<endl; 
			$$ = $1;
		}
	    | variable ASSIGNOP logic_expression 	 { 
			fout<<"expression : variable ASSIGNOP logic_expression"<<endl;
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
			fout<<"logic_expression : rel_expression"<<endl;
			$$ = $1;
		}
		| rel_expression LOGICOP rel_expression 	 { 
			fout<<"logic_expression : rel_expression LOGICOP rel_expression "<<endl;
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
			fout<<"rel_expression	: simple_expression"<<endl;
			$$ = $1;
		}
		| simple_expression RELOP simple_expression	 { 
			fout<<"rel_expression	: simple_expression RELOP simple_expression	"<<endl; 
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
			fout<<"simple_expression : term"<<endl;
			$$ = $1;
		}
		| simple_expression ADDOP term  { 
			fout<<"simple_expression : simple_expression ADDOP term  "<<endl;
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
			fout<<"term : unary_expression"<<endl; 
			$$ = $1;
		}
     |  term MULOP unary_expression { 
			fout<<"term :	term MULOP unary_expression "<<endl;
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
				fout<<"unary_expression :  ADDOP unary_expression"<<endl; 
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
				fout<<"unary_expression : NOT unary_expression"<<endl; 
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
				fout<<"unary_expression : factor"<<endl; 
				$$ = $1;
			}
		 ;
	
factor	: variable  { 
			fout<<"factor	: variable"<<endl; 
			$$=$1;
		}
	| LPAREN expression RPAREN  { 
			fout<<"factor	: LPAREN expression RPAREN"<<endl;
			$$ = $2;
		}
	| CONST_INT  { 
			fout<<"factor	: CONST_INT"<<endl; 
			fout<<$1->ivalue<<endl;
			$$ = $1;
		}
	| CONST_FLOAT { 
			fout<<"factor	: CONST_FLOAT"<<endl;
			fout<<$1->fvalue<<endl;
			$$ = $1;
		}
	| CONST_CHAR { 
			fout<<"factor	: CONST_CHAR "<<endl;
			fout<<$1->c<<endl;
			$$ = $1;
		}
	| factor INCOP  { 
			fout<<"factor	: factor INCOP"<<endl;
			if(type == "int"){
				$1->ivalue++;
			}
			//elseif(type == "char" && ){
			//	$1->c
			//}
		}
	| factor DECOP { 
			fout<<"factor	: factor DECOP"<<endl; 
			fout<<"factor	: factor INCOP"<<endl;
			if(type == "int"){
				$1->ivalue--;
			}
		}
	;
%%

main()
{
	freopen("input1.txt", "r", stdin);
    yyparse();
    exit(0);
}

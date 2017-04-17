
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
string functype;
Function *fn=NULL;
vector<SymbolInfo> params,args;

void yyerror(string s){
	errorcount++;
fprintf(error,"Line No. %d: Error Number %d %s program\n\n",line_count,errorcount,s.c_str());
}

%}

%token IF FOR DO INT FLOAT VOID SWITCH DEFAULT ELSE  WHILE BREAK RETURN CASE CONTINUE PRINTLN CONST_INT CONST_FLOAT CONST_CHAR ID ADDOP MULOP INCOP DECOP RELOP ASSINOP LOGICOP NOT LPAREN RPAREN LCURL RCURL LTHIRD RTHIRD COMMA SEMICOLON SINGLECOM MULTICOM 

%nonassoc only_if
%nonassoc ELSE

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
/**/
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

		fprintf(logout,"Line No. %d: func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n",line_count);
fprintf(logout,"%s\n\n",$2->getName().c_str());
		//cout<<"func_declaration :$1= "<<$1->getName()<<endl;
		//functype=$1->getName();
		if(table->Lookup($2->getName())==NULL)
		{
			table->Insert($2->getName(),"function");
			SymbolInfo *s=table->Lookup($2->getName());
			s->fp=new Function();
			s->fp->retype= $1->getName();
			s->fp->params=params;
			s->Print(); 
		} 
		else
		{
			fprintf(error,"Line No. %d: Multiple declaration Function %s\n\n",line_count,$2->getName().c_str());
		}
		fn=NULL;
		params.clear();
	}  
		 	;
		 
func_definition : type_specifier ID LPAREN parameter_list RPAREN 
	{
//cout<<"func_definition: $1= "<<$1->getName()<<endl;
//functype=$1->getName();
		cout<<"func_definition:\n";
		SymbolInfo *si=table->Lookup($2->getName());
		if(si==NULL)
		{
			table->Insert($2->getName(),"function");
			SymbolInfo *s=table->Lookup($2->getName());
			s->fp=new Function();
			s->fp->retype= $1->getName();
			s->fp->params=params;
			fn=s->fp;
			s->Print();
		}
		else
		{
			fn=si->fp;
			//fprintf(error,"Line No. %d: Multiple declaration Function %s\n\n",line_count,$2->getName().c_str());
			if(si->fp->retype==$1->getName())
			{
				if(si->fp->params.size()!=params.size())
				{fprintf(error,"Line No. %d: Parameters Size Mismatch of Function %s\n\n",line_count,$2->getName().c_str());	}
				else{
					for(int i=0;i<si->fp->params.size();i++)
					{
						if(si->fp->params[i].getName()!=params[i].getName()||si->fp->params[i].getType()!=params[i].getType())
						{
							fprintf(error,"Line No. %d: Parameters Mismatch of Function %s\n\n",line_count,$2->getName().c_str());					
						}
					}
				}
			}
			else{
				fprintf(error,"Line No. %d: Return-type Mismatch of Function %s\n\n",line_count,$2->getName().c_str());
			}
		}

		//cout<<"Rparen end\n";
		params.clear();

} compound_statement {
		fprintf(logout,"Line No. %d: func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n",line_count);
fprintf(logout,"%s\n\n",$2->getName().c_str());
}
 		 	;
 		 
parameter_list  : parameter_list COMMA type_specifier ID
{
	fprintf(logout,"Line No. %d: parameter_list  : parameter_list COMMA type_specifier ID\n",line_count);
	fprintf(logout,"%s\n\n",$4->getName().c_str());
	SymbolInfo sym($4->getName(),type);
	params.push_back(sym);
}

	| parameter_list COMMA type_specifier	 
{
	fprintf(logout,"Line No. %d: parameter_list  : parameter_list COMMA type_specifier\n\n",line_count);
}

 	| type_specifier ID
{
	fprintf(logout,"Line No. %d: parameter_list  : type_specifier ID\n",line_count);
	fprintf(logout,"%s\n\n",$2->getName().c_str());
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


compound_statement :LCURL 
	{
		table->EnterScope();
		//cout<<"Print it";
		if(fn!=NULL)
		{
			for(int i=0;i<fn->params.size();i++)
			{
				//cout<<fn->params[i].getName()<<endl;
				table->Insert(fn->params[i].getName(),fn->params[i].getType());
			}
			fn=NULL;
		}
	} 
statements RCURL { 
		 fprintf(logout,"Line No. %d: compound_statement : LCURL RCURL\n\n",line_count);
		 table->PrintAllScopeTable();
		 table->ExitScope();
	}
	| LCURL 
	{
		table->EnterScope();
		//cout<<"Print it";
		if(fn!=NULL)
		{
			for(int i=0;i<fn->params.size();i++)
			{
				//cout<<fn->params[i].getName()<<endl;
				table->Insert(fn->params[i].getName(),fn->params[i].getType());
			}
			fn=NULL;
		}
	}
	RCURL { 
		 fprintf(logout,"Line No. %d: compound_statement : LCURL RCURL\n\n",line_count);
		 table->PrintAllScopeTable();
		 table->ExitScope();
	}
		   ;

var_declaration	: type_specifier declaration_list SEMICOLON { fprintf(logout,"Line No. %d: var_declaration	: type_specifier declaration_list SEMICOLON\n\n",line_count); }

type_specifier	: INT  { fprintf(logout,"Line No. %d: type_specifier : INT \n\n",line_count); type="int"; $$=new SymbolInfo("int","type"); }
		| FLOAT { fprintf(logout,"Line No. %d: type_specifier : FLOAT\n\n",line_count); type="float";$$=new SymbolInfo("float","type"); }
		| VOID { fprintf(logout,"Line No. %d: type_specifier : VOID\n\n",line_count); type="void";$$=new SymbolInfo("void","type"); }
		;

declaration_list : declaration_list COMMA ID  { 
				fprintf(logout,"Line No. %d: declaration_list : declaration_list COMMA ID\n",line_count);
				fprintf(logout,"%s\n\n",$3->getName());
				if(type == "int"){
					
					SymbolInfo* s = new SymbolInfo($3->getName(), "int");
					s-> Token = "ID";
					if(table->Insert(s) == 0){
						yyerror("Multple declaration! ");
					}
				}
				if(type == "float"){
					SymbolInfo* s = new SymbolInfo($3->getName(), "float");
					s-> Token = "ID";
					if(table->Insert(s) == 0){
						yyerror("Multple declaration! ");
					}
				}
				if(type == "void"){
					yyerror("A variable cannot be declared as void!");
				}
				
				
			}
		 | declaration_list COMMA ID LTHIRD CONST_INT RTHIRD { 
				fprintf(logout,"Line No. %d: declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD\n",line_count);
				fprintf(logout,"%s\n\n",$3->getName());
				if(type == "int"){
					SymbolInfo* s = new SymbolInfo($3->getName(), "int");
					s-> Token = "ID";
					s->arraysize = $5->ivalue;
cout<<"Array size = "<<s->arraysize<<endl;
					s->array=new SymbolInfo*[s->arraysize];
for(int i=0;i<s->arraysize;i++)
{
cout<<"Creating pos = "<<i<<endl;
s->array[i]=new SymbolInfo("","int");
}
					if(table->Insert(s) == 0){
						yyerror("Multple declaration! ");
					}
					
				}
				if(type == "float"){
					SymbolInfo* s = new SymbolInfo($3->getName(), "float");
					s-> Token = "ID";
					s->arraysize = $5->ivalue;
					s->array=new SymbolInfo*[s->arraysize];
for(int i=0;i<s->arraysize;i++)
{
s->array[i]=new SymbolInfo("","float");
}
					if(table->Insert(s) == 0){
						yyerror("Multple declaration! ");
					}
				}
				if(type == "void"){
					yyerror("A variable cannot be declared as void!");
				}
			}
		 | ID  {
				fprintf(logout,"Line No. %d: declaration_list : ID\n",line_count);
				fprintf(logout,"%s\n\n",$1->getName());
				if(type == "int"){
					SymbolInfo* s = new SymbolInfo($1->getName(), "int");
					s-> Token = "ID";
					if(table->Insert(s) == 0){
						yyerror("Multple declaration! ");
					}
				}
				if(type == "float"){
					SymbolInfo* s = new SymbolInfo($1->getName(), "float");
					s-> Token = "ID";
					if(table->Insert(s) == 0){
						yyerror("Multple declaration! ");
					}
				}
				if(type == "void"){
					yyerror("A variable cannot be declared as void!");
				}
			}
		 | ID LTHIRD CONST_INT RTHIRD  { 
				fprintf(logout,"Line No. %d: program : unit\n\n",line_count);
				fprintf(logout,"%s\n\n",$1->getName());
				
				if(type == "int"){
					SymbolInfo* s = new SymbolInfo($1->getName(), "int");
					s-> Token = "ID";
					s->arraysize = $3->ivalue;
cout<<"Array size = "<<s->arraysize<<endl;
s->array=new SymbolInfo*[s->arraysize];
for(int i=0;i<s->arraysize;i++)
{
cout<<"Creating pos = "<<i<<endl;
s->array[i]=new SymbolInfo("element","int");
}
					if(table->Insert(s) == 0){
						yyerror("Multple declaration! ");
					}
				}
				if(type == "float"){
					SymbolInfo* s = new SymbolInfo($1->name, "int");
					s-> Token = "ID";
					s->arraysize = $3->ivalue;
s->array=new SymbolInfo*[s->arraysize];
for(int i=0;i<s->arraysize;i++)
{
s->array[i]=new SymbolInfo("","float");
}
					if(table->Insert(s) == 0){
						yyerror("Multple declaration! ");
					}
				}
				if(type == "void"){
					yyerror("A variable cannot be declared as void!");
				}
			}
		 ;

statements : statement  { fprintf(logout,"Line No. %d: statements : statement\n\n",line_count); }
	   | statements statement  { fprintf(logout,"Line No. %d: statements : statements statement\n\n",line_count); }
	   ;


statement  : var_declaration { 
fprintf(logout,"Line No. %d: statement  : var_declaration\n\n",line_count);
}
	   | expression_statement  {fprintf(logout,"Line No. %d: statement : expression_statement\n\n",line_count); }
	   | compound_statement  { fprintf(logout,"Line No. %d: statement : compound_statement\n\n",line_count); }
	   | FOR LPAREN expression_statement expression_statement expression RPAREN statement  { fprintf(logout,"Line No. %d: statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n\n",line_count); }
	   | IF LPAREN expression RPAREN statement %prec only_if { fprintf(logout,"Line No. %d: statement :  IF LPAREN expression RPAREN statement\n\n",line_count); }
	   | IF LPAREN expression RPAREN statement ELSE statement { fprintf(logout,"Line No. %d: statement : IF LPAREN expression RPAREN statement ELSE statement\n\n",line_count); }
	   | WHILE LPAREN expression RPAREN statement  { fprintf(logout,"Line No. %d: statement : WHILE LPAREN expression RPAREN statement\n\n",line_count); }
	   | PRINTLN LPAREN ID RPAREN SEMICOLON  { fprintf(logout,"Line No. %d: statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n\n",line_count); }
	   | RETURN expression SEMICOLON  { fprintf(logout,"Line No. %d: statement : RETURN expression SEMICOLON \n\n",line_count); }
	   ;
		
expression_statement	: SEMICOLON		 { fprintf(logout,"Line No. %d: expression_statement	: SEMICOLON\n\n",line_count); }	
			| expression SEMICOLON  { fprintf(logout,"Line No. %d: expression_statement	: expression SEMICOLON\n\n",line_count); cout<<"Variable : "<<$1->name<<" "<<$1->ivalue<<endl;}
			;
						
variable : ID	{ 
			fprintf(logout,"Line No. %d: variable : ID\n\n",line_count);
			SymbolInfo* temp = table->Lookup($1->getName());
			if (temp == NULL){
				yyerror("Undeclared variable! ");
			}
			else $$ = temp;
		}
		| ID LTHIRD expression RTHIRD  {
			fprintf(logout,"Line No. %d: variable : ID LTHIRD expression RTHIRD\n\n",line_count);
			cout<<$1->getName()<<endl;
			SymbolInfo* temp = table->Lookup($1->getName());
			if (temp == NULL){
				yyerror("Undeclared variable! ");
			}
			else{
				cout<<"Array index: "<<$3->ivalue<<endl;
cout<<"Temp Array Size = "<<temp->arraysize<<endl;
				if($3->ivalue >= temp->arraysize){
					yyerror("Array size overbound\n");
				}
				else {
					$$ = temp->array[$3->ivalue];
					fprintf(logout,"Array index insert: %d\n\n",$$->ivalue);
				}
				
			}
		}
	 ;
			
expression : logic_expression {
			fprintf(logout,"Line No. %d: expression : logic_expression\n\n",line_count);
			$$ = $1;
		}
	    | variable ASSINOP logic_expression 	 { 
			fprintf(logout,"Line No. %d: expression : variable ASSINOP logic_expression\n\n",line_count);
			//Print the symboltable here
			cout<<$3->ivalue<<endl;
			cout<<"Variable : "<<$1->name<<" "<<$1->ivalue<<endl;
			if($1->type == "int"){
				if($3->type == "int"){
					$1->ivalue = $3->ivalue;
				}
				if($3->type == "float"){
					$1->ivalue = $3->fvalue;
				}
				if($3->type == "char"){
					$1->ivalue = $3->c;
				}
			}
			else if($1->type == "float"){
				if($3->type == "int"){
					$1->fvalue = $3->ivalue;
				}
				if($3->type == "float"){
					$1->fvalue = $3->fvalue;
				}
				if($3->type == "char"){
					$1->fvalue = $3->c;
				}
			}
			/*else if($1->type == "char"){
				if($3->type == "int"){
					$1->c = $3->ivalue;
				}
				if($3->type == "float"){
					$1->c = $3->fvalue;
				}
				if($3->type == "char"){
					$1->c = $3->c;
				}
			}*/
			$$ = $1;
			//table->printTable(fout);
		}
	   ;
			
logic_expression : rel_expression 	 { 
			fprintf(logout,"Line No. %d: logic_expression : rel_expression\n\n",line_count);
			$$ = $1;
		}
		| rel_expression LOGICOP rel_expression 	 { 
			fprintf(logout,"Line No. %d: logic_expression : rel_expression\n\n",line_count);
			SymbolInfo* s = new SymbolInfo();
			s->type = "int";
			
			float f1, f2;
			if($1->type == "int"){
				f1 = $1->ivalue;
			}
			else if($1->type == "float"){
				f1 = $1->fvalue;
			}
			else if($1->type == "char"){
				f1 = $1->c;
			}
			
			if($3->type == "int"){
				f2 = $3->ivalue;
			}
			else if($3->type == "float"){
				f2 = $3->fvalue;
			}
			else if($3->type == "char"){
				f2 = $3->c;
			}
			
			if($2->name == "&&"){
				s->ivalue = f1&&f2;
			}
			else if ($2->name == "||"){
				s->ivalue = f1||f2;
			}
			$$ = s;
		}
		;
			
rel_expression	: simple_expression  { 
			fprintf(logout,"Line No. %d: rel_expression : simple_expression\n\n",line_count);
			$$ = $1;
		}
		| simple_expression RELOP simple_expression	 { 
			fprintf(logout,"Line No. %d: rel_expression : simple_expression RELOP simple_expression\n\n",line_count);
			SymbolInfo* s = new SymbolInfo();
			s->type = "int";
			if($2->name == "=="){
				if($1 == $2){
					s->ivalue = 1;
				}
				else {
					s->ivalue = 0;
				}
			}
			else if($2->name == "!="){
				if($1 != $2){
					s->ivalue = 1;
				}
				else {
					s->ivalue = 0;
				}
			}
			else if($2->name == ">"){
				if($1 > $2){
					s->ivalue = 1;
				}
				else {
					s->ivalue = 0;
				}
			}
			else if($2->name == "<"){
				if($1 < $2){
					s->ivalue = 1;
				}
				else {
					s->ivalue = 0;
				}
			}
			else if($2->name == ">="){
				if($1 >= $2){
					s->ivalue = 1;
				}
				else {
					s->ivalue = 0;
				}
			}
			else if($2->name == "<="){
				if($1 <= $2){
					s->ivalue = 1;
				}
				else {
					s->ivalue = 0;
				}
			}
			else yyerror("Relational operator error");
			$$ = s;
		}
		;
				
simple_expression : term  { 
			fprintf(logout,"Line No. %d: simple_expression : term\n\n",line_count);
			$$ = $1;
		}
		| simple_expression ADDOP term  { 
			fprintf(logout,"Line No. %d: simple_expression : simple_expression ADDOP term\n\n",line_count);
			SymbolInfo* s = new SymbolInfo();
			if($2->name == "+"){
				if($1->type == "int" && $3->type == "int"){
					s->ivalue = $1->ivalue + $3->ivalue;
					s->type = "int";
					$$ = s;
				}
				else if($1->type == "int" && $3->type == "float"){
					s->fvalue = $1->ivalue + $3->fvalue;
					s->type = "float";
					$$ = s;
				}
				else if($1->type == "float" && $3->type == "int"){
					s->fvalue = $1->fvalue + $3->ivalue;
					s->type = "float";
					$$ = s;
				}
				else if($1->type == "float" && $3->type == "float"){
					s->fvalue = $1->fvalue + $3->fvalue;
					s->type = "float";
					$$ = s;
				}
				else if($1->type == "char" && $3->type == "char"){
					s->ivalue = $1->c + $3->c;
					s->type = "int";
					$$ = s;
				}
				else if($1->type == "char" && $3->type == "int"){
					s->ivalue = $1->c + $3->ivalue;
					s->type = "int";
					$$ = s;
				}
				else if($1->type == "int" && $3->type == "char"){
					s->ivalue = $1->ivalue + $3->c;
					s->type = "int";
					$$ = s;
				}
				else if($1->type == "char" && $3->type == "float"){
					s->fvalue = $1->c + $3->fvalue;
					s->type = "float";
					$$ = s;
				}
				else if($1->type == "float" && $3->type == "char"){
					s->fvalue = $1->fvalue + $3->c;
					s->type = "float";
					$$ = s;
				}
				else {
					yyerror("Incompatible addition");
				}
				
			}
			else if($2->name == "-"){
				if($1->type == "int" && $3->type == "int"){
					s->ivalue = $1->ivalue - $3->ivalue;
					s->type = "int";
					$$ = s;
				}
				else if($1->type == "int" && $3->type == "float"){
					s->fvalue = $1->ivalue - $3->fvalue;
					s->type = "float";
					$$ = s;
				}
				else if($1->type == "float" && $3->type == "int"){
					s->fvalue = $1->fvalue - $3->ivalue;
					s->type = "float";
					$$ = s;
				}
				else if($1->type == "float" && $3->type == "float"){
					s->fvalue = $1->fvalue - $3->fvalue;
					s->type = "float";
					$$ = s;
				}
				else if($1->type == "char" && $3->type == "char"){
					s->ivalue = $1->c - $3->c;
					s->type = "int";
					$$ = s;
				}
				else if($1->type == "char" && $3->type == "int"){
					s->ivalue = $1->c - $3->ivalue;
					s->type = "int";
					$$ = s;
				}
				else if($1->type == "int" && $3->type == "char"){
					s->ivalue = $1->ivalue - $3->c;
					s->type = "int";
					$$ = s;
				}
				else if($1->type == "char" && $3->type == "float"){
					s->fvalue = $1->c - $3->fvalue;
					s->type = "float";
					$$ = s;
				}
				else if($1->type == "float" && $3->type == "char"){
					s->fvalue = $1->fvalue - $3->c;
					s->type = "float";
					$$ = s;
				}
				else {
					yyerror("Incompatible addition");
				}
			}
		}
		;
					
term :	unary_expression { 
			fprintf(logout,"Line No. %d: term : unary_expression\n\n",line_count);
			$$ = $1;
		}
     |  term MULOP unary_expression { 
			fprintf(logout,"Line No. %d: term : term MULOP unary_expression\n\n",line_count);
						SymbolInfo* s = new SymbolInfo();
			if($2->name == "*"){
				if($1->type == "int" && $3->type == "int"){
					s->ivalue = $1->ivalue * $3->ivalue;
					s->type = "int";
					$$ = s;
				}
				else if($1->type == "int" && $3->type == "float"){
					s->fvalue = $1->ivalue * $3->fvalue;
					s->type = "float";
					$$ = s;
				}
				else if($1->type == "float" && $3->type == "int"){
					s->fvalue = $1->fvalue * $3->ivalue;
					s->type = "float";
					$$ = s;
				}
				else if($1->type == "float" && $3->type == "float"){
					s->fvalue = $1->fvalue * $3->fvalue;
					s->type = "float";
					$$ = s;
				}
				else if($1->type == "char" && $3->type == "char"){
					s->ivalue = $1->c * $3->c;
					s->type = "int";
					$$ = s;
				}
				else if($1->type == "char" && $3->type == "int"){
					s->ivalue = $1->c * $3->ivalue;
					s->type = "int";
					$$ = s;
				}
				else if($1->type == "int" && $3->type == "char"){
					s->ivalue = $1->ivalue * $3->c;
					s->type = "int";
					$$ = s;
				}
				else if($1->type == "char" && $3->type == "float"){
					s->fvalue = $1->c * $3->fvalue;
					s->type = "float";
					$$ = s;
				}
				else if($1->type == "float" && $3->type == "char"){
					s->fvalue = $1->fvalue * $3->c;
					s->type = "float";
					$$ = s;
				}
				else {
					yyerror("Incompatible Multiplication");
				}
				
			}
						else if($2->name == "/"){
				if($1->type == "int" && $3->type == "int"){
					s->ivalue = $1->ivalue / $3->ivalue;
					s->type = "int";
					$$ = s;
				}
				else if($1->type == "int" && $3->type == "float"){
					s->fvalue = $1->ivalue / $3->fvalue;
					s->type = "float";
					$$ = s;
				}
				else if($1->type == "float" && $3->type == "int"){
					s->fvalue = $1->fvalue / $3->ivalue;
					s->type = "float";
					$$ = s;
				}
				else if($1->type == "float" && $3->type == "float"){
					s->fvalue = $1->fvalue / $3->fvalue;
					s->type = "float";
					$$ = s;
				}
				else if($1->type == "char" && $3->type == "char"){
					s->ivalue = $1->c / $3->c;
					s->type = "int";
					$$ = s;
				}
				else if($1->type == "char" && $3->type == "int"){
					s->ivalue = $1->c / $3->ivalue;
					s->type = "int";
					$$ = s;
				}
				else if($1->type == "int" && $3->type == "char"){
					s->ivalue = $1->ivalue / $3->c;
					s->type = "int";
					$$ = s;
				}
				else if($1->type == "char" && $3->type == "float"){
					s->fvalue = $1->c / $3->fvalue;
					s->type = "float";
					$$ = s;
				}
				else if($1->type == "float" && $3->type == "char"){
					s->fvalue = $1->fvalue / $3->c;
					s->type = "float";
					$$ = s;
				}
				else {
					yyerror("Incompatible Division");
				}
				
			}
			//mod
			else if($2->name == "%"){
				if($1->type == "int" && $3->type == "int"){
					s->ivalue = $1->ivalue % $3->ivalue;
					s->type = "int";
					$$ = s;
				}
				else if($1->type == "int" && $3->type == "float"){
					yyerror("Warning! Cannot take mod of float or with a float");
				}
				else if($1->type == "float" && $3->type == "int"){
					yyerror("Warning! Cannot take mod of float or with a float");
				}
				else if($1->type == "float" && $3->type == "float"){
					yyerror("Warning! Cannot take mod of float or with a float");
				}
				else if($1->type == "char" && $3->type == "char"){
					s->ivalue = $1->c % $3->c;
					s->type = "int";
					$$ = s;
				}
				else if($1->type == "char" && $3->type == "int"){
					s->ivalue = $1->c % $3->ivalue;
					s->type = "int";
					$$ = s;
				}
				else if($1->type == "int" && $3->type == "char"){
					s->ivalue = $1->ivalue % $3->c;
					s->type = "int";
					$$ = s;
				}
				else if($1->type == "char" && $3->type == "float"){
					yyerror("Warning! Cannot take mod of float or with a float");
				}
				else if($1->type == "float" && $3->type == "char"){
					yyerror("Warning! Cannot take mod of float or with a float");
				}
				else {
					yyerror("Incompatible Modulation");
				}
				
			}
			
		}
     ;

unary_expression : ADDOP unary_expression   { 
				fprintf(logout,"Line No. %d: unary_expression : ADDOP unary_expression\n\n",line_count);
				if($2->name == "+"){
					$$ = $2;
				}
				else if($2->name == "-"){
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
				fprintf(logout,"Line No. %d: unary_expression : NOT unary_expression\n\n",line_count);
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
				fprintf(logout,"Line No. %d: unary_expression : factor\n\n",line_count);
				$$ = $1;
			}
		 ;
	
factor	: variable  { 
			fprintf(logout,"Line No. %d: factor : variable\n\n",line_count);
			$$=$1;
		}
	| ID LPAREN argument_list RPAREN { //ajoy have to do

fprintf(logout,"Line No. %d: factor : ID LPAREN argument_list RPAREN\n\n",line_count);
SymbolInfo * s=table->Lookup($1->name);
if(s!=NULL)
{
if(s->fp==NULL)
{
string temp=$1->name+" is not a Function!";
yyerror(temp);
}
else
{

if(s->fp->params.size()!=args.size())
{
fprintf(error,"Line No. %d: Parameters Size Mismatch of Function Call %s\n\n",line_count,$1->getName().c_str());	
}
else{
	for(int i=0;i<s->fp->params.size();i++)
	{
		if(s->fp->params[i].getType()!=args[i].getType())
		{
			fprintf(error,"Line No. %d: Parameters Mismatch of Function Call %s\n\n",line_count,$1->getName().c_str());					
		}
	}
}
}
}
else
{
yyerror("Undeclared Function "+$1->name+" call!");
}

SymbolInfo* si = new SymbolInfo($1->name,"int");
si->ivalue=0;
$$=si;
args.clear();
	}

	| LPAREN expression RPAREN  { 
			fprintf(logout,"Line No. %d: factor :  LPAREN expression RPAREN\n\n",line_count);
			$$ = $2;
		}
	| CONST_INT  { 
			fprintf(logout,"Line No. %d: factor : CONST_INT\n\n",line_count);
			fprintf(logout,"%d\n\n",$1->ivalue);
			$$ = $1;
		}
	| CONST_FLOAT { 
			fprintf(logout,"Line No. %d: factor : CONST_FLOAT\n",line_count);
			fprintf(logout,"%d\n\n",$1->fvalue);
			$$ = $1;
		}
	| CONST_CHAR { 
			fprintf(logout,"Line No. %d: factor : CONST_CHAR\n\n",line_count);
			fprintf(logout,"%c\n\n",$1->c);
			$$ = $1;
		}
	| variable INCOP  { 
			fprintf(logout,"Line No. %d: factor : variable INCOP\n\n",line_count);
			if(type == "int"){
				$1->ivalue++;
			}
			else if(type == "float"){
				$1->fvalue++;
			}
			else if(type == "char"){
				$1->c++;
			}
		}
	| variable DECOP {  
			fprintf(logout,"Line No. %d: factor : variable DECOP\n\n",line_count);
			if(type == "int"){
				$1->ivalue--;
			}
			else if(type == "float"){
				$1->fvalue--;
			}
			else if(type == "char"){
				$1->c--;
			}
		}
	;

argument_list : argument_list COMMA logic_expression
{
fprintf(logout,"Line No. %d: argument_list : argument_list COMMA logic_expression\n\n",line_count);
args.push_back(*($3));
}
	      | logic_expression
{
fprintf(logout,"Line No. %d: argument_list : logic_expression\n\n",line_count);
args.push_back(*($1));
}
	      |
{
fprintf(logout,"Line No. %d: argument_list : empty\n\n",line_count);
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



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
FILE *codes;
bool symtabprint=false;
SymbolTable* table = new SymbolTable(7,1);

int errorcount = 0;
extern int line_count;

string type;
string functype;
Function *fn=NULL;
vector<SymbolInfo> params,args;
bool paramerr=false;

void yyerror(string s){
	errorcount++;
fprintf(error,"Error at Line %d: %s \n\n",line_count,s.c_str());
fprintf(logout,"Error at Line %d: %s \n\n",line_count,s.c_str());
}
//Assembly Portion
string asmb = "";
string declaration = "";

int labelCount=0;
int tempCount=0;

char *newLabel()
{
	char *lb= new char[4];
	strcpy(lb,"L");
	char b[3];
	sprintf(b,"%d", labelCount);
	labelCount++;
	strcat(lb,b);
	return lb;
}

char *newTemp()
{
	char *t= new char[4];
	strcpy(t,"t");
	char b[3];
	sprintf(b,"%d", tempCount);
	tempCount++;
	strcat(t,b);
	return t;
}

string newAdd(string s,int i)
{
	ostringstream oss;
	oss<<s<<i;
	return oss.str();
}

%}
%define parse.error verbose
%token IF FOR DO INT FLOAT VOID SWITCH DEFAULT ELSE  WHILE BREAK RETURN CASE CONTINUE PRINTLN CONST_INT CONST_FLOAT ID ADDOP MULOP INCOP DECOP RELOP ASSINOP LOGICOP NOT LPAREN RPAREN LCURL RCURL LTHIRD RTHIRD COMMA SEMICOLON SINGLECOM MULTICOM


%left ADDOP
%left MULOP

%nonassoc only_if
%nonassoc ELSE

%%

start : program
	{
		//fprintf(logout,"Line %d: start : program\n\n",line_count);
		fprintf(logout,"Total Lines: %d\n\nTotal Errors: %d\n\n",line_count,errorcount);

		$$ = new SymbolInfo();
		asmb += ".model small\n.stack 100h\n.data\n"+ declaration +"\n"+".code\nPRINTLN PROC\n@END_IF1:\nXOR CX,CX\nMOV BX,10D\n@REPEAT1:\nXOR DX,DX\nDIV BX\nPUSH DX\nINC CX\nOR AX,AX\nJNE @REPEAT1\nMOV AH,2\n@PRINT_LOOP:\nPOP DX\nOR DL,30H\nINT 21H\nLOOP @PRINT_LOOP\nRET\nPRINTLN ENDP\n";
		asmb += "\nmain proc\n\tmov ax,@data\n\tmov ds,ax\n\tmov es,ax";
		$$->code += asmb + $1->code;
		//cout<<$5->code;

		$$->code += "\n\tint 21h\n\tmov ah,4ch\n\tint 21h\nmain endp\nend main\n";
		fprintf(codes,"%s\n",$$->code.c_str());
	}
	;

program : program unit
	{
		fprintf(logout,"Line %d: program : program unit\n\n",line_count);
		$$=$1;
		$$->code+=$2->code;
	}
	|
	unit
	{
		fprintf(logout,"Line %d: program : unit\n\n",line_count);
		$$=$1;
	}
| error unit {
	fprintf(logout,"Line %d: unit : error unit\n\n",line_count);
	$$=$2;
}
	;

unit :var_declaration
		{
			fprintf(logout,"Line %d: unit : var_declaration\n\n",line_count);
			$$=$1;
		}
     	|
     	func_declaration
     	{
/**/
			fprintf(logout,"Line %d: unit : func_declaration\n\n",line_count);
$$=$1;
     	}
     	|
     	func_definition
     	{
			fprintf(logout,"Line %d: unit : func_definition\n\n",line_count);
			$$=$1;
/*
| error SEMICOLON {fprintf(logout,"Line %d: unit : error SEMICOLON\n\n",line_count);}
		| error RCURL {fprintf(logout,"Line %d: unit : error RCURL\n\n",line_count);}
*/
     	}

     	;

func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON
	{

		fprintf(logout,"Line %d: func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n",line_count);
fprintf(logout,"%s\n\n",$2->getName().c_str());
		//cout<<"func_declaration :$1= "<<$1->getName()<<endl;
		//functype=$1->getName();
if(paramerr==true)
{
yyerror("Parameters can't be declared without name in function"+$2->getName());
paramerr=false;
}
else {
		if(table->Lookup($2->getName())==NULL)
		{
bool flag=true;
for(int i=0;i<params.size();i++)
{
if(params[i].name==$2->getName()){
flag=false;
ostringstream oss;
oss<<"Function name matched with "<<i+1<<"th parameter in "<<$2->getName();
yyerror(oss.str());
break;
}
}
if(flag){

			table->Insert($2->getName(),"function");
			SymbolInfo *s=table->Lookup($2->getName());
			s->fp=new Function();
			s->fp->retype= $1->getName();
			s->fp->params=params;
			s->Print();
		}
}
		else
		{
			//fprintf(logout,"Error at Line %d: Multiple declaration Function %s\n\n",line_count,$2->getName().c_str());
			yyerror("Multiple declaration Function "+$2->getName());
		}
		fn=NULL;

}
params.clear();
 }


| type_specifier ID LPAREN RPAREN SEMICOLON
	{

		fprintf(logout,"Line %d: func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON\n",line_count);
fprintf(logout,"%s\n\n",$2->getName().c_str());
		//cout<<"func_declaration :$1= "<<$1->getName()<<endl;
		//functype=$1->getName();
if(paramerr==true)
{
yyerror("Parameters can't be declared without name in function"+$2->getName());
paramerr=false;
}
else {
		if(table->Lookup($2->getName())==NULL)
		{
bool flag=true;
for(int i=0;i<params.size();i++)
{
if(params[i].name==$2->getName()){
flag=false;
ostringstream oss;
oss<<"Function name matched with "<<i+1<<"th parameter in "<<$2->getName();
yyerror(oss.str());
break;
}
}
if(flag){

			table->Insert($2->getName(),"function");
			SymbolInfo *s=table->Lookup($2->getName());
			s->fp=new Function();
			s->fp->retype= $1->getName();
			s->fp->params=params;
			s->Print();
		}
}
		else
		{
			//fprintf(logout,"Error at Line %d: Multiple declaration Function %s\n\n",line_count,$2->getName().c_str());
			yyerror("Multiple declaration Function "+$2->getName());
		}
		fn=NULL;

}
params.clear();
 }
		 	;

func_definition : type_specifier ID LPAREN parameter_list RPAREN
	{
if(paramerr==true)
{
yyerror("Parameters can't be declared without name in function "+$2->getName());
paramerr=false;
}
else {
//cout<<"func_definition: $1= "<<$1->getName()<<endl;
//functype=$1->getName();
		cout<<"func_definition:\n";
		SymbolInfo *si=table->Lookup($2->getName());
		if(si==NULL)
		{
bool flag=true;
for(int i=0;i<params.size();i++)
{
if(params[i].name==$2->getName()){
flag=false;
ostringstream oss;
oss<<"Function name matched with "<<i+1<<"th parameter in "<<$2->getName();
yyerror(oss.str());
break;
}
}
if(flag){

			table->Insert($2->getName(),"function");
			SymbolInfo *s=table->Lookup($2->getName());
			s->fp=new Function();
			s->fp->retype= $1->getName();
			s->fp->params=params;
			fn=s->fp;
			s->Print();
}
		}
		else
		{
			fn=si->fp;
			//fprintf(error,"Line %d: Multiple declaration Function %s\n\n",line_count,$2->getName().c_str());
			if(si->fp->retype==$1->getName())
			{
				if(si->fp->params.size()!=params.size()){
//fprintf(logout,"Error at Line %d: Parameters Size Mismatch of Function %s\n\n",line_count,$2->getName().c_str());
yyerror("Parameters Size Mismatch of Function "+$2->getName());
}
				else{
					for(int i=0;i<si->fp->params.size();i++)
					{
						if(si->fp->params[i].getName()!=params[i].getName()||si->fp->params[i].getType()!=params[i].getType())
						{
							//fprintf(logout,"Error at Line %d: %dth parameter Mismatch of Function %s\n\n",line_count,i+1,$2->getName().c_str());
ostringstream oss;
oss<<i+1<<"th parameter Mismatch of Function "<<$2->getName();
yyerror(oss.str());
						}
if(params[i].name==$2->getName()){
ostringstream oss;
oss<<"Function name matched with "<<i+1<<"th parameter in "<<$2->getName();
yyerror(oss.str());
break;
}
					}
				}
			}
			else{
				fprintf(logout,"Line %d: Return-type Mismatch of Function %s\n\n",line_count,$2->getName().c_str());
yyerror("Return-type Mismatch of Function "+$2->getName());
			}
		}
}
		//cout<<"Rparen end\n";
		params.clear();

} compound_statement {
		fprintf(logout,"Line %d: func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n",line_count);
fprintf(logout,"%s\n\n",$2->getName().c_str());
}



| type_specifier ID LPAREN RPAREN
	{
if(paramerr==true)
{
yyerror("Parameters can't be declared without name in function "+$2->getName());
paramerr=false;
}
else {
//cout<<"func_definition: $1= "<<$1->getName()<<endl;
//functype=$1->getName();
		cout<<"func_definition:\n";
		SymbolInfo *si=table->Lookup($2->getName());
		if(si==NULL)
		{
bool flag=true;
for(int i=0;i<params.size();i++)
{
if(params[i].name==$2->getName()){
flag=false;
ostringstream oss;
oss<<"Function name matched with "<<i+1<<"th parameter in "<<$2->getName();
yyerror(oss.str());
break;
}
}
if(flag){

			table->Insert($2->getName(),"function");
			SymbolInfo *s=table->Lookup($2->getName());
			s->fp=new Function();
			s->fp->retype= $1->getName();
			s->fp->params=params;
			fn=s->fp;
			s->Print();
}
		}
		else
		{
			fn=si->fp;
			//fprintf(error,"Line %d: Multiple declaration Function %s\n\n",line_count,$2->getName().c_str());
			if(si->fp->retype==$1->getName())
			{
				if(si->fp->params.size()!=params.size()){
//fprintf(logout,"Error at Line %d: Parameters Size Mismatch of Function %s\n\n",line_count,$2->getName().c_str());
yyerror("Parameters Size Mismatch of Function "+$2->getName());
}
				else{
					for(int i=0;i<si->fp->params.size();i++)
					{
						if(si->fp->params[i].getName()!=params[i].getName()||si->fp->params[i].getType()!=params[i].getType())
						{
							//fprintf(logout,"Error at Line %d: %dth parameter Mismatch of Function %s\n\n",line_count,i+1,$2->getName().c_str());
ostringstream oss;
oss<<i+1<<"th parameter Mismatch of Function "<<$2->getName();
yyerror(oss.str());
						}
if(params[i].name==$2->getName()){
ostringstream oss;
oss<<"Function name matched with "<<i+1<<"th parameter in "<<$2->getName();
yyerror(oss.str());
break;
}
					}
				}
			}
			else{
				fprintf(logout,"Line %d: Return-type Mismatch of Function %s\n\n",line_count,$2->getName().c_str());
yyerror("Return-type Mismatch of Function "+$2->getName());
			}
		}
}
		//cout<<"Rparen end\n";
		params.clear();

} compound_statement {
		fprintf(logout,"Line %d: func_definition : type_specifier ID LPAREN RPAREN compound_statement\n",line_count);
fprintf(logout,"%s\n\n",$2->getName().c_str());
}
 		 	;

parameter_list  : parameter_list COMMA type_specifier ID
{
	fprintf(logout,"Line %d: parameter_list  : parameter_list COMMA type_specifier ID\n",line_count);
	fprintf(logout,"%s\n\n",$4->getName().c_str());
	SymbolInfo sym($4->getName(),type);
	params.push_back(sym);
}

	| parameter_list COMMA type_specifier
{
	fprintf(logout,"Line %d: parameter_list  : parameter_list COMMA type_specifier\n\n",line_count);
	paramerr=true;
}

 	| type_specifier ID
{
	fprintf(logout,"Line %d: parameter_list  : type_specifier ID\n",line_count);
	fprintf(logout,"%s\n\n",$2->getName().c_str());
	SymbolInfo sym($2->getName(),type);
	params.push_back(sym );
}

 	| type_specifier
{
 	fprintf(logout,"Line %d: parameter_list  : type_specifier\n\n",line_count);
	paramerr=true;
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
		 fprintf(logout,"Line %d: compound_statement : LCURL statements RCURL\n\n",line_count);
		 symtabprint=true;
		 fprintf(symtable,"Line No %d\n\n",line_count);
		 table->PrintAllScopeTable();
		 symtabprint=false;
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
		 fprintf(logout,"Line %d: compound_statement : LCURL RCURL\n\n",line_count);
		 table->PrintAllScopeTable();
		 table->ExitScope();
	}
		   ;

var_declaration	: type_specifier declaration_list SEMICOLON { fprintf(logout,"Line %d: var_declaration	: type_specifier declaration_list SEMICOLON\n\n",line_count); }

type_specifier	: INT  { fprintf(logout,"Line %d: type_specifier : INT \n\n",line_count); type="int"; $$=new SymbolInfo("int",type); }
		| FLOAT { fprintf(logout,"Line %d: type_specifier : FLOAT\n\n",line_count); type="float";$$=new SymbolInfo("float",type); }
		| VOID { fprintf(logout,"Line %d: type_specifier : VOID\n\n",line_count); type="void";$$=new SymbolInfo("void",type); }
		;

declaration_list : declaration_list COMMA ID  {
				fprintf(logout,"Line %d: declaration_list : declaration_list COMMA ID\n",line_count);
				fprintf(logout,"%s\n\n",$3->getName().c_str());
SymbolInfo* temp = new SymbolInfo();

if($1->Token!="error"){
				if(type == "int"){

					SymbolInfo* s = new SymbolInfo($3->getName(), "int");
					s-> Token = "ID";
					if(table->Insert(s) == 0){
						yyerror("Multple declaration! ");
temp->Token="error";
					}
				}
				if(type == "float"){
					SymbolInfo* s = new SymbolInfo($3->getName(), "float");
					s-> Token = "ID";
					if(table->Insert(s) == 0){
						yyerror("Multple declaration! ");
temp->Token="error";
					}
				}
				if(type == "void"){
					yyerror("A variable cannot be declared as void!");
temp->Token="error";
				}
}
else {temp->Token="error";}

$$=temp;
			}
		 | declaration_list COMMA ID LTHIRD CONST_INT RTHIRD {
				fprintf(logout,"Line %d: declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD\n",line_count);
				fprintf(logout,"%s\n%d\n\n",$3->getName().c_str(),$5->ivalue);
SymbolInfo* temp = new SymbolInfo();

if($1->Token!="error"){

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
temp->Token="error";
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
temp->Token="error";
					}
				}
				if(type == "void"){
					yyerror("A variable cannot be declared as void!");
temp->Token="error";
				}
}
else {temp->Token="error";}

$$=temp;
			}
		 | ID  {
				fprintf(logout,"Line %d: declaration_list : ID\n",line_count);
				fprintf(logout,"%s\n\n",$1->getName().c_str());
SymbolInfo* temp = new SymbolInfo();

				if(type == "int"){
					SymbolInfo* s = new SymbolInfo($1->getName(), "int");
					s-> Token = "ID";
					if(table->Insert(s) == 0){
						yyerror("Multple declaration! ");
temp->Token="error";
					}
				}
				if(type == "float"){
					SymbolInfo* s = new SymbolInfo($1->getName(), "float");
					s-> Token = "ID";
					if(table->Insert(s) == 0){
						yyerror("Multple declaration! ");
temp->Token="error";
					}
				}
				if(type == "void"){
					yyerror("A variable cannot be declared as void!");
temp->Token="error";
				}

$$=temp;
			}
		 | ID LTHIRD CONST_INT RTHIRD  {
				fprintf(logout,"Line %d: declaration_list : ID LTHIRD CONST_INT RTHIRD\n",line_count);
				fprintf(logout,"%s\n%d\n\n",$1->getName().c_str(),$3->ivalue);
SymbolInfo* temp = new SymbolInfo();

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
temp->Token="error";
					}
				}
				if(type == "float"){
					SymbolInfo* s = new SymbolInfo($1->name, "float");
					s-> Token = "ID";
					s->arraysize = $3->ivalue;
s->array=new SymbolInfo*[s->arraysize];
for(int i=0;i<s->arraysize;i++)
{
s->array[i]=new SymbolInfo("","float");
}
					if(table->Insert(s) == 0){
						yyerror("Multple declaration! ");
temp->Token="error";
					}
				}
				if(type == "void"){
					yyerror("A variable cannot be declared as void!");
temp->Token="error";
				}

$$=temp;
			}
		 ;

statements : statement  { fprintf(logout,"Line %d: statements : statement\n\n",line_count); }
	   | statements statement  { fprintf(logout,"Line %d: statements : statements statement\n\n",line_count); }
	   ;


statement  : var_declaration {
fprintf(logout,"Line %d: statement  : var_declaration\n\n",line_count);
}
	   | expression_statement  {fprintf(logout,"Line %d: statement : expression_statement\n\n",line_count); }
	   | compound_statement  { fprintf(logout,"Line %d: statement : compound_statement\n\n",line_count); }
	   | FOR LPAREN expression_statement expression_statement expression RPAREN statement  { fprintf(logout,"Line %d: statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n\n",line_count); }
	   | IF LPAREN expression RPAREN statement %prec only_if { fprintf(logout,"Line %d: statement :  IF LPAREN expression RPAREN statement\n\n",line_count); }
	   | IF LPAREN expression RPAREN statement ELSE statement { fprintf(logout,"Line %d: statement : IF LPAREN expression RPAREN statement ELSE statement\n\n",line_count); }
	   | WHILE LPAREN expression RPAREN statement  { fprintf(logout,"Line %d: statement : WHILE LPAREN expression RPAREN statement\n\n",line_count); }
	   | PRINTLN LPAREN ID RPAREN SEMICOLON  { fprintf(logout,"Line %d: statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n\n",line_count); }
	   | RETURN expression SEMICOLON  { fprintf(logout,"Line %d: statement : RETURN expression SEMICOLON \n\n",line_count); }

	   | error SEMICOLON {}
;

expression_statement	: SEMICOLON		 { fprintf(logout,"Line %d: expression_statement	: SEMICOLON\n\n",line_count); }
			| expression SEMICOLON  { fprintf(logout,"Line %d: expression_statement	: expression SEMICOLON\n\n",line_count); cout<<"Variable : "<<$1->name<<" "<<$1->ivalue<<endl;}
			;

variable : ID	{
			fprintf(logout,"Line %d: variable : ID\n",line_count);
			fprintf(logout,"%s\n\n",$1->getName().c_str());
			SymbolInfo* temp = table->Lookup($1->getName());
			if (temp == NULL){
				yyerror("Undeclared variable "+$1->getName());
temp=new SymbolInfo();
temp->Token="error";
			}
else if(temp->arraysize!=-1)
{
yyerror("Array can't be used without index in "+$1->getName());
temp = new SymbolInfo();
temp->Token="error";
}
else
{
	temp=new SymbolInfo(temp);
}

			temp->address=newAdd(temp->name,table->id);
			$$ = temp;
		}
		| ID LTHIRD expression RTHIRD  {
			fprintf(logout,"Line %d: variable : ID LTHIRD expression RTHIRD\n",line_count);
			fprintf(logout,"%s\n\n",$1->getName().c_str());
SymbolInfo* temp = new SymbolInfo();

if($3->Token!="error"){
			cout<<$1->getName()<<endl;
			temp = table->Lookup($1->getName());
			if (temp == NULL){
				yyerror("Undeclared variable "+$1->getName());
temp = new SymbolInfo();
temp->Token="error";
			}
			else if($3->type!="int"){
yyerror("Array index must be integer"+$1->getName());
temp = new SymbolInfo();
temp->Token="error";
}
else if(temp->arraysize==-1)
{
yyerror("Non-Array variable can't be used with index "+$1->getName());
temp = new SymbolInfo();
temp->Token="error";
cout<<"Temp Token ="<<temp->Token<<endl;
}
else{
				cout<<"Array index: "<<$3->ivalue<<endl;
cout<<"Temp Array Size = "<<temp->arraysize<<endl;
				if($3->ivalue >= temp->arraysize){
					yyerror("Array size overbound\n");
temp = new SymbolInfo();
temp->Token="error";
				}
				else {
					temp = temp->array[$3->ivalue];
					temp=new SymbolInfo(temp);
					temp->code=$3->code+"mov bx, " +$3->address +"\nadd bx, bx\n";
					temp->address=newAdd(temp->name,table->id);
					//fprintf(logout,"Array index insert: %d\n\n",$$->ivalue);
				}

			}
		}
else {temp->Token="error";}
cout<<"Temp Token 2="<<temp->Token<<endl;
$$=temp;

}

	 ;

expression : logic_expression {
			fprintf(logout,"Line %d: expression : logic_expression\n\n",line_count);
			$$ = $1;
		}
	    | variable ASSINOP logic_expression 	 {
			fprintf(logout,"Line %d: expression : variable ASSINOP logic_expression\n\n",line_count);
SymbolInfo* temp = new SymbolInfo();

cout<<"Variable Token= "<<$1->Token<<endl;
if($1->Token!="error" && $3->Token!="error"){
			//Print the symboltable here
			cout<<"Variable : "<<$1->name<<" "<<$1->ivalue<<" "<<$1->type<<endl;
			cout<<"Variable : "<<$3->name<<" "<<$3->ivalue<<" "<<$3->type<<endl;
			if($1->type == "int"){
				if($3->type == "int"){
					$1->ivalue = $3->ivalue;
				}
				else if($3->type=="void"){
yyerror("Calling void function in an expression is not allowed");
temp->Token="error";
}
				else{
					yyerror("Type Mismatch");
temp->Token="error";
				}
			}
			else if($1->type == "float"){
				if($3->type == "int"){
					$1->fvalue = $3->ivalue;
				}
				else if($3->type == "float"){
					$1->fvalue = $3->fvalue;
				}
			else if($3->type=="void"){
yyerror("Calling void function in an expression is not allowed");
temp->Token="error";
}
				else {
					yyerror("Type Mismatch");
temp->Token="error";
				}
			}
			else {
					yyerror("Type Mismatch");
temp->Token="error";
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
			cout<<"After assign: "<<$1->ivalue<<endl;
			//$$ = $1;
			table->PrintAllScopeTable();
		}
else {temp->Token="error";}

$$=temp;
}

	   ;

logic_expression : rel_expression 	 {
			fprintf(logout,"Line %d: logic_expression : rel_expression\n\n",line_count);
			$$ = $1;
		}
		| rel_expression LOGICOP rel_expression 	 {
			fprintf(logout,"Line %d: logic_expression : rel_expression\n\n",line_count);
			SymbolInfo* s = new SymbolInfo();
if($1->Token!="error" && $3->Token!="error"){

			s->type = "int";

			float f1, f2;
			if($1->type == "int"){
				f1 = $1->ivalue;
			}
			else if($1->type == "float"){
				f1 = $1->fvalue;
			}

			if($3->type == "int"){
				f2 = $3->ivalue;
			}
			else if($3->type == "float"){
				f2 = $3->fvalue;
			}

			if($2->name == "&&"){
				s->ivalue = f1&&f2;
			}
			else if ($2->name == "||"){
				s->ivalue = f1||f2;
			}
			//$$ = s;
}
else {s->Token="error";}

$$=s;
		}
		;

rel_expression	: simple_expression  {
			fprintf(logout,"Line %d: rel_expression : simple_expression\n\n",line_count);
			$$ = $1;
		}
		| simple_expression RELOP simple_expression	 {
			fprintf(logout,"Line %d: rel_expression : simple_expression RELOP simple_expression\n\n",line_count);
			SymbolInfo* s = new SymbolInfo();
if($1->Token!="error" && $3->Token!="error"){

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
			else {
yyerror("Relational operator error");
s->Token="error";
}
			//$$ = s;
		}
else {s->Token="error";}

$$=s;
}


		;

simple_expression : term  {
			fprintf(logout,"Line %d: simple_expression : term\n\n",line_count);
			$$ = $1;
		}
		| simple_expression ADDOP term  {
			fprintf(logout,"Line %d: simple_expression : simple_expression ADDOP term\n\n",line_count);
			SymbolInfo* s = new SymbolInfo();

if($1->Token!="error" && $3->Token!="error"){
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
				else {
					yyerror("Incompatible addition");
s->Token="error";
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
				else {
					yyerror("Incompatible addition");
s->Token="error";
				}
			}
}
else {s->Token="error";}

$$=s;
		}
		;

term :	unary_expression {
			fprintf(logout,"Line %d: term : unary_expression\n\n",line_count);
			$$ = $1;
		}
     |  term MULOP unary_expression {
			fprintf(logout,"Line %d: term : term MULOP unary_expression\n\n",line_count);
						SymbolInfo* s = new SymbolInfo();
if($1->Token!="error" && $3->Token!="error"){

fprintf(logout,"%s\n\n",$2->name.c_str());
			if($2->name == "*"){
				if($1->type == "int" && $3->type == "int"){
					s->ivalue = $1->ivalue * $3->ivalue;
					s->type = "int";
					//$$ = s;
				}
				else if($1->type == "int" && $3->type == "float"){
					s->fvalue = $1->ivalue * $3->fvalue;
					s->type = "float";
					//$$ = s;
				}
				else if($1->type == "float" && $3->type == "int"){
					s->fvalue = $1->fvalue * $3->ivalue;
					s->type = "float";
					//$$ = s;
				}
				else if($1->type == "float" && $3->type == "float"){
					s->fvalue = $1->fvalue * $3->fvalue;
					s->type = "float";
					//$$ = s;
				}
				else {
					yyerror("Incompatible Multiplication");
s->Token="error";
				}

			}
						else if($2->name == "/"){
				if($1->type == "int" && $3->type == "int"){
					s->ivalue = $1->ivalue / $3->ivalue;
					s->type = "int";
					//$$ = s;
				}
				else if($1->type == "int" && $3->type == "float"){
					s->fvalue = $1->ivalue / $3->fvalue;
					s->type = "float";
					//$$ = s;
				}
				else if($1->type == "float" && $3->type == "int"){
					s->fvalue = $1->fvalue / $3->ivalue;
					s->type = "float";
					//$$ = s;
				}
				else if($1->type == "float" && $3->type == "float"){
					s->fvalue = $1->fvalue / $3->fvalue;
					s->type = "float";
					//$$ = s;
				}
				else {
					yyerror("Incompatible Division");
s->Token="error";
				}

			}
			//mod
			else if($2->name == "%"){
				cout<<"Mod Variable : "<<$1->name<<" "<<$1->ivalue<<" "<<$1->type<<endl;
				cout<<"Mod Variable : "<<$3->name<<" "<<$3->ivalue<<" "<<$3->type<<endl;
				if($1->type == "int" && $3->type == "int"){
					s->ivalue = $1->ivalue % $3->ivalue;
					cout<<s->ivalue<<endl;
					s->type = "int";
					//$$ = s;
				}
				else {
					yyerror("Non-Integer operand on modulus operator");
s->Token="error";
				}

			}
//code generation
			$$=$1;
			$$->code += $3->code;
			$$->code += "mov ax, "+ $1->address+"\n";
			$$->code += "mov bx, "+ $3->address +"\n";
			char *t=newTemp();
			declaration += string(t) + " dw ?\n";
			if($2->name=="*"){
				$$->code += "mul bx\n";
				$$->code += "mov "+ string(t) + ", ax\n";
			}
			else if($2->name=="/"){
				// clear dx, perform 'div bx' and mov ax to temp
				$$->code += "MOV DX, 0\n\t";
				$$->code += "DIV BX\n\t";
				$$->code += "MOV "+string(t)+", ax\n\t";
			}
			else{
				// clear dx, perform 'div bx' and mov dx to temp
				$$->code += "MOV DX, 0\n\t";
				$$->code += "DIV BX\n\t";
				$$->code += "MOV "+string(t)+", dx\n\t";
			}
			$$->address=string(t);
			//cout << endl << $$->code << endl;
			//delete $3;
}
else {s->Token="error";}

$$=s;
		}
     ;

unary_expression : ADDOP unary_expression   {
				fprintf(logout,"Line %d: unary_expression : ADDOP unary_expression\n\n",line_count);
SymbolInfo* temp = new SymbolInfo();
if($2->Token!="error"){
				if($2->name == "+"){
					$$ = $2;
				}
				else if($2->name == "-"){
					if(type == "int"){
						$$->ivalue = $2->ivalue * -1;
					}
					else if(type == "float"){
						$$->fvalue = $2->fvalue * -1;
					}
					char *t=newTemp();
					declaration += string(t) + " dw ?\n";
					temp->code="mov ax, " + $2->address + "\n";
					temp->code+="neg ax\n";
					temp->code+="mov "+string(t)+", ax";
					temp->address=string(t);

				}

}
else {temp->Token="error";}
$$=temp;
}
		 | NOT unary_expression  {
fprintf(logout,"Line %d: unary_expression : NOT unary_expression\n\n",line_count);
SymbolInfo* temp = new SymbolInfo();

				if($2->Token!="error"){

				if(type == "int"){
					if($2->ivalue) {
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
				char *t=newTemp();
				declaration += string(t) + " dw ?\n";
				temp->code="mov ax, " + $2->address + "\n";
				temp->code+="not ax\n";
				temp->code+="mov "+string(t)+", ax";
				temp->address=string(t);
}
else {temp->Token="error";}

				$$ = temp;
			}
		 | factor  {
				fprintf(logout,"Line %d: unary_expression : factor\n\n",line_count);
				$$ = $1;
			}
		 ;

factor	: variable  {
			fprintf(logout,"Line %d: factor : variable\n\n",line_count);
			$$=$1;

			if($$->arraysize==-1){

			}
			else{
				char *t= newTemp();
				declaration += string(t) + " dw ?\n";
				$$->code+="mov ax, " + $1->address + "[bx]\n";
				$$->code+= "mov " + string(t) + ", ax\n";
				$$->address=string(t);
			}
		}
	| ID LPAREN argument_list RPAREN {

fprintf(logout,"Line %d: factor : ID LPAREN argument_list RPAREN\n\n",line_count);

SymbolInfo* si = new SymbolInfo();
SymbolInfo * s=table->Lookup($1->name);
if(s!=NULL)
{
if(s->fp==NULL)
{
yyerror($1->name+" is not a Function");
si = new SymbolInfo();
si->Token="error";
}
else
{

if(s->fp->params.size()!=args.size())
{
//fprintf(logout,"Error at Line %d: Total Number of Arguments mismatch in funtion %s\n\n",line_count,$1->getName().c_str());
yyerror("Total Number of Arguments mismatch in funtion "+$1->getName());
si = new SymbolInfo();
si->Token="error";
}
else{
	for(int i=0;i<s->fp->params.size();i++)
	{
		if(s->fp->params[i].getType()!=args[i].getType())
		{
			//fprintf(logout,"Error at Line %d: %dth argument mismatch in function %s\n\n",line_count,i+1,$1->getName().c_str());
ostringstream oss;
oss<<i+1<<"th argument mismatch in function "<<$2->getName();
yyerror(oss.str());
si = new SymbolInfo();
si->Token="error";
		}
	}

si->name=$1->name;
si->type=s->fp->retype;
}
}
}
else
{
yyerror("Undeclared Function "+$1->name);
si = new SymbolInfo();
si->Token="error";
}

si->ivalue=0;
si->fvalue=0;
$$=si;
args.clear();
	}

	| LPAREN expression RPAREN  {
			fprintf(logout,"Line %d: factor :  LPAREN expression RPAREN\n\n",line_count);
			$$ = $2;
		}
	| CONST_INT  {
			fprintf(logout,"Line %d: factor : CONST_INT\n",line_count);
			fprintf(logout,"%d\n\n",$1->ivalue);
			$$ = $1;
		}
	| CONST_FLOAT {
			fprintf(logout,"Line %d: factor : CONST_FLOAT\n",line_count);
			fprintf(logout,"%lf\n\n",$1->fvalue);
			$$ = $1;
		}
	| variable INCOP  {
if($1->Token!="error")
{
			fprintf(logout,"Line %d: factor : variable INCOP\n\n",line_count);
			if(type == "int"){
				$1->ivalue++;
			}
			else if(type == "float"){
				$1->fvalue++;
			}
			$1->code += "INC " + $1->address + "\n\t";
}
$$=$1;
}
	| variable DECOP {
if($1->Token!="error")
{
			fprintf(logout,"Line %d: factor : variable DECOP\n\n",line_count);
			if(type == "int"){
				$1->ivalue--;
			}
			else if(type == "float"){
				$1->fvalue--;
			}
			$1->code += "DEC " + $1->address + "\n\t";

}
$$=$1;
}
	;

argument_list : arguments {
fprintf(logout,"Line %d: argument_list : argumets\n\n",line_count);
$$=$1;
}
                    | {
fprintf(logout,"Line %d: argument_list : empty\n\n",line_count);
$$= new SymbolInfo();
}
                    ;


arguments : arguments COMMA logic_expression
{
fprintf(logout,"Line %d: argument_list : argument_list COMMA logic_expression\n\n",line_count);
if($1->Token!="error" && $3->Token!="error"){
args.push_back(*($3));
$$= new SymbolInfo();
}
else if($1->Token=="error")$$=$1;
else $$=$3;
}
	      | logic_expression
{
	fprintf(logout,"Line %d: argument_list : logic_expression\n\n",line_count);

	if($1->Token!="error"){
	args.push_back(*($1));
	}
	$$=$1;
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
	codes= fopen("code.asm","w");
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

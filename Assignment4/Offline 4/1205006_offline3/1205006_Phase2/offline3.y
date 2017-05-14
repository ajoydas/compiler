
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
string asmb = "", declaration = "";

void yyerror(string s){
	errorcount++;
	fout<<"Error Number "<<errorcount<<" "<<s<<" at line: "<<linecount;
	;
}

int labelCount=0;
int tempCount=0;

string newLabel()
{
	string lb="L";
	char b[3];
	sprintf(b,"%d", labelCount);
	labelCount++;
	lb+=b; //changed
	return lb;
}

string newTemp()
{
	string t = "t";
	char b[3];
	sprintf(b,"%d", tempCount);
	tempCount++;
	t+=b; //changed
	return t;
}


int yylex(void);

%}

%token IF ELSE FOR WHILE INT FLOAT DOUBLE CHAR RETURN VOID MAIN PRINTLN ADDOP MULOP ASSIGNOP RELOP LOGICOP SEMICOLON COMMA LPAREN RPAREN LCURL RCURL LTHIRD RTHIRD INCOP DECOP CONST_INT CONST_FLOAT CONST_CHAR ID NOT


%%
Program : INT MAIN LPAREN RPAREN compound_statement { 
			fout<<"Program : INT MAIN LPAREN RPAREN compound_statement"<<endl;
			//$$=$5;
			$$ = new SymbolInfo();
			asmb += ".model small\n.stack 100h\n.data\n"+declaration+"\n"+".code\n";
			asmb += "PRINTLN PROC\n@END_IF1:\nXOR CX,CX\nMOV BX,10D\n@REPEAT1:\nXOR DX,DX\nDIV BX\nPUSH DX\nINC CX\nOR AX,AX\nJNE @REPEAT1\nMOV AH,2\n@PRINT_LOOP:\nPOP DX\nOR DL,30H\nINT 21H\nLOOP @PRINT_LOOP\nRET\nPRINTLN ENDP\n";
			
			asmb += "\nmain proc\n";
			$$->code += $5->code;
			
			$$->code += asmb;
			$$->code += "\nmain endp\nend main\n";
			ofstream aout("code.asm");
			aout << $$->code;
		}
	;


compound_statement : LCURL var_declaration statements RCURL { 
			fout<<"compound_statement : LCURL var_declaration statements RCURL"<<endl;
			$$=$3;
			$$->code=$2->code+$3->code;
		}
	   | LCURL statements RCURL LCURL { 
			fout<<"compound_statement : LCURL statements RCURL LCURL "<<endl;
			$$=$2;
		}
	   | LCURL RCURL { 
			fout<<"compound_statement : LCURL RCURL "<<endl; 
			
		}
	   ;

			 
var_declaration	: type_specifier declaration_list SEMICOLON { 
			fout<<"var_declaration	: type_specifier declaration_list SEMICOLON "<<endl; 
			$$=$1;
			$$->code+=$3->code;
		}
		|  var_declaration type_specifier declaration_list SEMICOLON {
			fout<<"var_declaration	: var_declaration type_specifier declaration_list SEMICOLON"<<endl; 
			$$=$2;
		}
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
				
				
				declaration += "dw "+ $3->Name+" ?\n";
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
				
				int l = $3->ivalue;
				declaration += "dw "+ $1->Name + "? ";
				for(int i =0; i<l; i++){
					declaration += ", ?";
				}
				declaration += "\n";
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
				
				declaration += "dw "+ $1->Name+" ?\n";
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
				
				int l = $3->ivalue;
				declaration += "dw "+ $1->Name + "? ";
				for(int i =0; i<l; i++){
					declaration += ", ?";
				}
				declaration += "\n";
			}
		 ;

statements : statement  { 
			fout<<"statements : statement"<<endl; 
			$$=$1;
		}
	   | statements statement  { 
			fout<<"statements : statements statement"<<endl; 
			$$=$1;
			$$->code += $2->code;
		}
	   ;


statement  : expression_statement  { 
			fout<<"statement  : expression_statement"<<endl; 
			$$=$1;
		}
	   | compound_statement  { 
			fout<<"statement  : compound_statement"<<endl; 
			$$=$1;
		}
	   | FOR LPAREN expression_statement expression_statement expression RPAREN statement  {
			fout<<"statement  : FOR LPAREN expression_statement expression_statement expression RPAREN statement"<<endl;
			$$=$3;
			string lebel1 = newLabel();
			string lebel2 = newLabel();
			
			$$->code += lebel1;
			$$->code += $4->code;
			$$->code += "cmp "+$4->Name+", 1\n";
			$$->code += "jne "+lebel2+"\n";
			$$->code += $7->code;
			$$->code += $5->code;
			$$->code += lebel2+":\n";
		}
	   | IF LPAREN expression RPAREN statement { 
			fout<<"statement  : IF LPAREN expression RPAREN statement"<<endl; 
			$$=$3;
					
			string label=newLabel();
			$$->code+="mov ax, "+$3->Name+"\n";
			$$->code+="cmp ax, 0\n";
			$$->code+="je "+label+"\n";
			$$->code+=$5->code;
			$$->code+=label+":\n";
			
			$$->Name = "if";//not necessary
		}
	   | IF LPAREN expression RPAREN statement ELSE statement { 
			fout<<"statement  : IF LPAREN expression RPAREN statement ELSE statement"<<endl; 
			$$=$3;
					
			string label1=newLabel();
			string label2=newLabel();
			$$->code+="mov ax, "+$3->Name+"\n";
			$$->code+="cmp ax, 0\n";
			$$->code+="je "+label1+"\n";
			$$->code+=$5->code;
			$$->code+="jmp " + label2+"\n";
			$$->code+=label1+":\n";
			$$->code+=$7->code;
			$$->code+=label2+":\n";
			
		}
	   | WHILE LPAREN expression RPAREN statement  { 
			fout<<"statement  : WHILE LPAREN expression RPAREN statement "<<endl; 
			string lebel1 = newLabel();
			string lebel2 = newLabel();
			
			$$->code += $3->code;
			$$->code += lebel1;
			$$->code += "cmp "+$3->Name+", 1\n";
			$$->code += "jne "+lebel2+"\n";
			$$->code += $5->code;
			$$->code += "jmp "+lebel1+"\n";
			$$->code += lebel2+":\n";
		}
	   | PRINTLN LPAREN ID RPAREN SEMICOLON  { 
			fout<<"statement  : PRINTLN LPAREN ID RPAREN SEMICOLON "<<endl; 
			$$=new SymbolInfo();
			$$->code += $3->code;
			$$->code += "mov ax, "+$3->Name+"\n";
			$$->code += "call PRINTLN\n";
		}
	   | RETURN expression SEMICOLON  { 
			fout<<"statement  : RETURN expression SEMICOLON "<<endl; 
			$$=$1;
		}
	   ;
		
expression_statement	: SEMICOLON		 {
				fout<<"expression_statement	: SEMICOLON"<<endl;
				$$=new SymbolInfo();
				$$->Name = ";";
				$$->Token = "SEMICOLON";
				$$->code="";
			}	
			| expression SEMICOLON  { fout<<"expression_statement	: expression SEMICOLON"<<endl; $$=$1;}
//			;
						
variable : ID	{ 
			fout<<"variable : ID"<<endl;
			SymbolInfo* temp = table->searchTable($1->Name);
			//cout<<"Found Variable Name: "<<temp->Name<<" Token: "<<temp->Token<<" iValue: "<<temp->ivalue<<" Datatype: "<<temp->datatype<<endl;
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
						$$->arrIndexHolder=$3->Name;
						$$->code=$3->code;
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
			
			//cout<<"Value of logic expression: "<<$3->ivalue<<" type: "<<$3->datatype<<endl;
			SymbolInfo *s = new SymbolInfo();
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
				s->ivalue = $1->ivalue;
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
				s->fvalue = $1->fvalue;
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
				s->c = $1->c;
			}
			
			s->code = $1->code;
			s->Name = $1->Name;
			s->Token = $1->Token; //Problem!!
			
			$$ = $1;
			$$->code +=$3->code+$1->code;
			$$->code+="mov ax, "+$3->Name+"\n";
			if($$->arrIndexHolder==""){ //actualy it is more appropriate to use arrayLength to make decision
				$$->code+= "mov "+$1->Name+", ax\n";
			}
			
			else{
				$$->code+="lea di, " + $1->Name+"\n";
				for(int i=0;i<2;i++){
					$$->code += "add di, " + $1->arrIndexHolder +"\n";
				}
				$$->code+= "mov [di], ax\n";
				$$->arrIndexHolder="";
			}
				
			/*cout<<"While assigning: "<<$1->Name<<" Token: "<<$1->Token<<" iValue: "<<$1->ivalue<<" Datatype: "<<$1->datatype<<endl;*/
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
			string temp = newTemp();
			string label1 = newLabel();
			string label2 = newLabel();
			string label3 = newLabel();
			s->datatype = "int";
			
			s->code += $1->code;
			s->code += $3->code;
			
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
			$$ = s;
			$$->code +="mov ax, " + $1->Name +"\n";
			$$->code +="mov bx, " + $3->Name +"\n";
			
			if($2->Name == "&&"){
				$$->ivalue = f1&&f2;
				//
				$$->code += "cmp ax, 0\nje "+label1+"cmp bx, 0\nje "+label1;
				$$->code += label2+":\nmov "+ temp+", 1\njmp "+label3;
				$$->code += label1+":\nmov "+ temp+", 0\n";
			}
			else if ($2->Name == "||"){
				$$->ivalue = f1||f2;
				$$->code += "cmp ax, 0\njne "+label1+"cmp bx, 0\njne "+label1;
				$$->code += label2+":\nmov "+ temp+", 0\njmp "+label3;
				$$->code += label1+":\nmov "+ temp+", 1\n";
			}
			$$->Name = temp;
		}
		;
			
rel_expression	: simple_expression  { 
			fout<<"rel_expression	: simple_expression"<<endl;
			$$ = $1;
		}
		| simple_expression RELOP simple_expression	 { 
			fout<<"rel_expression	: simple_expression RELOP simple_expression	"<<endl; 
			SymbolInfo* s = new SymbolInfo();
			string temp = newTemp();
			
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
			
			$$->code +=$1->code;
			$$->code+=$3->code;
			$$->code+="mov ax, " + $1->Name+"\n";
			$$->code+="cmp ax, " + $3->Name+"\n";
			
			string label1=newLabel();
			string label2=newLabel();
			
			if($2->Name == "<"){
				$$->code+="jl " + label1+"\n";
			}
			else if($2->Name == "<="){
				$$->code+="jle " + label1+"\n";
			}
			else if($2->Name == ">"){
				$$->code+="jg " + label1+"\n";
			}
			else if($2->Name == ">="){
				$$->code+="jge " + label1+"\n";
			}
			else if($2->Name == "=="){
				$$->code+="je " + label1+"\n";
			}
			else{
				$$->code+="jne " + label1+"\n";
			}
			
			$$->code+="mov "+temp +", 0\n";
			$$->code+="jmp "+label2 +"\n";
			$$->code+=label1+":\nmov "+string(temp)+", 1\n";
			$$->code+=label2+":\n";
			$$->Name =temp;
		}
		;
				
simple_expression : term  { 
			fout<<"simple_expression : term"<<endl;
			$$ = $1;
		}
		| simple_expression ADDOP term  { 
			fout<<"simple_expression : simple_expression ADDOP term  "<<endl;
			SymbolInfo* s = new SymbolInfo();
			string temp = newTemp();
			
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
			
			$$->code += $1->code;
			$$->code+=$3->code;
			
			if($2->Name == "+"){
				$$->code += "MOV AX, " + $1->Name + "\n";
				$$->code += "ADD AX, " + $3->Name + "\n";
				$$->code += "MOV "+ $1->Name + ", AX\n";
			}
			else {
				$$->code += "MOV AX, " + $1->Name + "\n";
				$$->code += "SUB AX, " + $3->Name + "\n";
				$$->code += "MOV "+ $1->Name + ", AX\n";
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
			string temp = newTemp();
			
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
			
			$$->code += $1->code;
			$$->code += $3->code;
			
			$$->code += "mov ax, "+ $1->Name+"\n";
			$$->code += "mov bx, "+ $3->Name +"\n";
			
			if($2->Name == "*"){
				$$->code += "mul bx\n";
				$$->code += "mov "+ temp + ", ax\n";
			}
			else if($2->Name == "/"){
				// clear dx, perform 'div bx' and mov ax to temp
				$$->code += "MOV DX, 0\n";
				$$->code += "DIV BX\n";
				$$->code += "MOV "+temp+", ax\n";
			}
			else if($2->Name == "%"){
				// clear dx, perform 'div bx' and mov dx to temp
				$$->code += "MOV DX, 0\n";
				$$->code += "DIV BX\n";
				$$->code += "MOV "+temp+", dx\n";
			}
			$$->Name = temp;
			
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
				string t=newTemp();
				$$->code="mov AX, " + $2->Name + "\n";
				$$->code+="NOT AX\n";
				$$->code+="MOV "+ t +", AX\n";
				$$->Name = t;
			}
		 | factor  { 
				fout<<"unary_expression : factor"<<endl; 
				$$ = $1;
			}
		 ;
	
factor	: variable  { 
			fout<<"factor	: variable"<<endl; 
			$$=$1;
			
			if($$->arrIndexHolder!=""){//actualy it is better use arrayLength to make decision
				$$->code+="lea di, " + string($1->Name)+"\n";
				
				$$->code += "add di, " + $1->arrIndexHolder +"\n";
				$$->code += "add di, " + $1->arrIndexHolder +"\n";
				
				string temp = newTemp();
				$$->code+= "MOV AX, [di]\n";
				$$->code+= "MOV " + temp + ", AX\n";
				$$->Name = temp;
				$$->arrIndexHolder="";
			}
			cout << endl;
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
			$$ = $1;
			$$->code += "INC " + string($1->Name) + "\n";
		}
	| factor DECOP { 
			fout<<"factor	: factor DECOP"<<endl; 
			if(type == "int"){
				$1->ivalue--;
			}
			$$ = $1;
			$$->code += "DEC " + string($1->Name) + "\n";
		}
	;
%%

main()
{
	freopen("input1.txt", "r", stdin);
    yyparse();
    exit(0);
}

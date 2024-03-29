
%{
#include<bits/stdc++.h>
#include "SymbolTable.h"
#define YYSTYPE SymbolInfo*
using namespace std;

int yyparse(void);
int yylex(void);
extern FILE *yyin;

FILE *logout;
//FILE *error;
//FILE *symtable;
FILE *codes;
FILE *optimized;
bool symtabprint=false;
SymbolTable* table = new SymbolTable(7,1);

int errorcount = 0;
extern int line_count;
bool debugging=false;
string type;
string functype;
Function *fn=NULL;
Function *fn2=NULL;
vector<SymbolInfo> params,args;
bool paramerr=false;

void yyerror(string s){
	errorcount++;
//fprintf(error,"Error at Line %d: %s \n\n",line_count,s.c_str());
fprintf(logout,"Error at Line %d: %s \n\n",line_count,s.c_str());
}
//Assembly Portion
string asmb = "";
string declaration = "";

int labelCount=0;
int tempCount=0;
string funcName="";
int funcId=0;
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

void optimize(char *s)
{
	//printf ("Splitting string \"%s\" into tokens:\n",s);
	char *end_str;
	char *token =strtok_r(s, "\n", &end_str);
	bool prev=false;
	while (token != NULL)
	{
		char *end_token,*reg1,*reg2,*reg3,*reg4;
		if(debugging)printf("%s\n", token);
		char *saved=(char*)malloc(sizeof(char) * (strlen(token)+1));
		strcpy(saved,token);

		char *token2 = strtok_r(token, " ", &end_token);
		if(debugging)printf("%s\n", token2);
		if(!strcmp(token2,"mov"))
		{
			if(debugging)printf("Mov found = %s\n", token2);
			reg3 = strtok_r(NULL, ",", &end_token);
			reg4 = end_token;
			if(debugging)printf("Reg3 = %s Reg4 = %s\n\n", reg3,reg4);
			if(prev && !strcmp(reg1,reg4) &&!strcmp(reg2,reg3))
			{
				if(debugging)printf("Match found\n");
				fprintf(optimized,"mov %s,%s\n",reg1,reg2);
				prev=false;
			}
			else
			{
				//cout<<"####1"<<endl;
				if(prev){
				fprintf(optimized,"mov %s,%s\n",reg1,reg2);
				}
                //cout<<"####2"<<endl;
				prev=true;
                reg1=reg3;
                reg2=reg4;
			}
		}
        else {
                 if(prev)
                 {
                    fprintf(optimized,"mov %s,%s\n",reg1,reg2);
                 }
                prev=false;
                fprintf(optimized,"%s\n",saved);
            }
		token = strtok_r(NULL, "\n", &end_str);
	}
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
		asmb += ".model small\n.stack 100h\n.data\n"+ declaration +"\n"+".code\nPRINTLN PROC\nEND_IF1:\nXOR CX,CX\nMOV BX,10D\nREPEAT1:\nXOR DX,DX\nDIV BX\nPUSH DX\nINC CX\nOR AX,AX\nJNE REPEAT1\nMOV AH,2\nPRINT_LOOP:\nPOP DX\nOR DL,30H\nINT 21H\nLOOP PRINT_LOOP\nMOV DL,0DH\nINT 21H\nMOV DL,0AH\nINT 21H\nRET\nPRINTLN ENDP\n\n";
		$$->code += asmb + $1->code;
		//cout<<$5->code;

		$$->code += "end main\n";
		if(!errorcount){
			fprintf(codes,"%s\n",$$->code.c_str());
			//optimize( const_cast<char*>($$->code.c_str()));
			//char cha[]="mov ax,@data\nmov ds, ax\nmov es, ax\nmov t1,ax\nmov ax,t1\nadd y1, ax\nmov t2, ax\nadd ax, bx\nmov ax, t2\nmov ah, 4ch\nint 21h\n";
			//char *ch=cha;
			optimize( const_cast<char*>($$->code.c_str()));
		}
	}
	;

program : program unit
	{
		if(debugging)fprintf(logout,"Line %d: program : program unit\n\n",line_count);
		$$=$1;
		$$->code+=$2->code;
	}
	|
	unit
	{
		if(debugging)fprintf(logout,"Line %d: program : unit\n\n",line_count);
		$$=$1;

	}
	| error unit {
		if(debugging)fprintf(logout,"Line %d: unit : error unit\n\n",line_count);
		$$=$2;
	}
	;

unit :var_declaration
		{
			if(debugging)fprintf(logout,"Line %d: unit : var_declaration\n\n",line_count);
			$$=$1;
		}
     	|
     	func_declaration
     	{
/**/
			if(debugging)fprintf(logout,"Line %d: unit : func_declaration\n\n",line_count);
			$$=$1;
     	}
     	|
     	func_definition
     	{
			if(debugging)fprintf(logout,"Line %d: unit : func_definition\n\n",line_count);
			$$=$1;
/*
| error SEMICOLON {fprintf(logout,"Line %d: unit : error SEMICOLON\n\n",line_count);}
		| error RCURL {fprintf(logout,"Line %d: unit : error RCURL\n\n",line_count);}
*/
     	}

     	;

func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON
	{

		if(debugging)fprintf(logout,"Line %d: func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n",line_count);
if(debugging)fprintf(logout,"%s\n\n",$2->getName().c_str());
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

		if(debugging)fprintf(logout,"Line %d: func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON\n",line_count);
if(debugging)fprintf(logout,"%s\n\n",$2->getName().c_str());
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
			s->fp->retaddress=(string)newTemp();
			declaration +=s->fp->retaddress+ " dw ?\n";
			s->fp->params=params;
			fn=s->fp;
			fn2=s->fp;
			funcName=$2->getName();
			s->Print();
}
		}
		else
		{
			fn=si->fp;
			fn2=si->fp;
			funcName=si->getName();
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
		if(debugging)fprintf(logout,"Line %d: func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n",line_count);
if(debugging)fprintf(logout,"%s\n\n",$2->getName().c_str());
cout<<"Line %d: func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n";
	$$=new SymbolInfo();
	$$->code=funcName+" proc\n";
	//cout<<"####1"<<endl;
	if(funcName=="main")
	{
		//cout<<"####2"<<endl;
		$$->code+= "mov ax,@data\nmov ds,ax\nmov es,ax\n";
		$$->code+=$7->code;
	}
	else
	{
		$$->code+="push BP\nmov BP,SP\npush ax\npush bx\npush cx\npush dx\n";
		string popParam="";
		for(int i=fn2->params.size()-1;i>=0;i--)
		{
			ostringstream oss;
			string st=newAdd(fn2->params[i].getName(),funcId);
			oss<<"push "+st+"\n";
			oss<<"mov ax,[BP+"<<4+(fn2->params.size()-1-i)*2<<"]\n";
			$$->code+=oss.str();

			declaration +=st+ " dw ?\n";
			$$->code+="mov "+st+",ax\n";
		}
		$$->code+=$7->code;
		for(int i=0;i<fn2->params.size();i++)
		{
			string st=newAdd(fn2->params[i].getName(),funcId);
			$$->code+="pop "+st+"\n";
		}
		$$->code+="pop dx\npop cx\npop bx\npop ax\npop BP\n";
		ostringstream oss;
		oss<<"Ret "<<fn2->params.size()*2<<"\n";
		$$->code+=oss.str();
	}
	if(funcName=="main")$$->code+="mov ah,4ch\nint 21h\n";
	$$->code+=funcName+" endp\n\n";
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
			s->fp->retaddress=(string)newTemp();
			declaration +=s->fp->retaddress+ " dw ?\n";
			s->fp->params=params;
			fn=s->fp;
			fn2=s->fp;
			funcName=$2->getName();
			s->Print();
}
		}
		else
		{
			fn=si->fp;
			fn2=si->fp;
			funcName=si->getName();
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
		if(debugging)fprintf(logout,"Line %d: func_definition : type_specifier ID LPAREN RPAREN compound_statement\n",line_count);
		if(debugging)fprintf(logout,"%s\n\n",$2->getName().c_str());
		$$=new SymbolInfo();
		$$->code=funcName+" proc\n";
		//cout<<"####1"<<endl;
		if(funcName=="main")
		{
			//cout<<"####2"<<endl;
			$$->code+= "mov ax,@data\nmov ds,ax\nmov es,ax\n";
			$$->code+=$6->code;
		}
		else
		{
			$$->code+="push BP\nmov BP,SP\npush ax\npush bx\npush cx\npush dx\n";
			string popParam="";
			for(int i=fn2->params.size()-1;i>=0;i--)
			{
				ostringstream oss;
				string st=newAdd(fn2->params[i].getName(),funcId);
				oss<<"push "+st+"\n";
				oss<<"mov ax,[BP+"<<4+(fn2->params.size()-1-i)*2<<"]\n";
				$$->code+=oss.str();

				declaration +=st+ " dw ?\n";
				$$->code+="mov "+st+",ax\n";
			}
			$$->code+=$6->code;
			for(int i=0;i<fn2->params.size();i++)
			{
				string st=newAdd(fn2->params[i].getName(),funcId);
				$$->code+="pop "+st+"\n";
			}
			$$->code+="pop dx\npop cx\npop bx\npop ax\npop BP\n";
			ostringstream oss;
			oss<<"Ret "<<fn2->params.size()*2<<"\n";
			$$->code+=oss.str();
		}
		if(funcName=="main")$$->code+="mov ah,4ch\nint 21h\n";
		$$->code+=funcName+" endp\n\n";
}
 		 	;

parameter_list  : parameter_list COMMA type_specifier ID
{
	if(debugging)fprintf(logout,"Line %d: parameter_list  : parameter_list COMMA type_specifier ID\n",line_count);
	if(debugging)fprintf(logout,"%s\n\n",$4->getName().c_str());
	SymbolInfo sym($4->getName(),type);
	params.push_back(sym);
}

	| parameter_list COMMA type_specifier
{
	if(debugging)fprintf(logout,"Line %d: parameter_list  : parameter_list COMMA type_specifier\n\n",line_count);
	paramerr=true;
}

 	| type_specifier ID
{
	if(debugging)fprintf(logout,"Line %d: parameter_list  : type_specifier ID\n",line_count);
	if(debugging)fprintf(logout,"%s\n\n",$2->getName().c_str());
	SymbolInfo sym($2->getName(),type);
	params.push_back(sym );
}

 	| type_specifier
{
 	if(debugging)fprintf(logout,"Line %d: parameter_list  : type_specifier\n\n",line_count);
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
			funcId=table->id;
			fn=NULL;
		}
	}
statements RCURL {

		$$=$3;
		cout<<"Line %d: compound_statement : LCURL statements RCURL\n\n";
		//cout<<"####1"<<$$->code<<endl;

		if(debugging)fprintf(logout,"Line %d: compound_statement : LCURL statements RCURL\n\n",line_count);
		//symtabprint=true;
		//if(debugging)fprintf(symtable,"Line No %d\n\n",line_count);
		//table->PrintAllScopeTable();
		//symtabprint=false;
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
		 if(debugging)fprintf(logout,"Line %d: compound_statement : LCURL RCURL\n\n",line_count);
		 //table->PrintAllScopeTable();
		 table->ExitScope();
		 $$=$2;
	}
		   ;

var_declaration	: type_specifier declaration_list SEMICOLON {
	 if(debugging)fprintf(logout,"Line %d: var_declaration	: type_specifier declaration_list SEMICOLON\n\n",line_count);
	 $$=$2;
	 cout<<"Line %d: var_declaration	: type_specifier declaration_list SEMICOLON\n\n";
	 cout<<"#####1"<<$2->address<<endl;
 }

type_specifier	: INT  { if(debugging)fprintf(logout,"Line %d: type_specifier : INT \n\n",line_count);
type="int"; $$=new SymbolInfo("int",type); }
		| FLOAT { if(debugging)fprintf(logout,"Line %d: type_specifier : FLOAT\n\n",line_count);
		type="float";$$=new SymbolInfo("float",type); }
		| VOID { if(debugging)fprintf(logout,"Line %d: type_specifier : VOID\n\n",line_count);
		 type="void";$$=new SymbolInfo("void",type); }
		;




declaration_list : declaration_list COMMA ID  {
				if(debugging)fprintf(logout,"Line %d: declaration_list : declaration_list COMMA ID\n",line_count);
				if(debugging)fprintf(logout,"%s\n\n",$3->getName().c_str());
SymbolInfo* temp = new SymbolInfo();

if($1->Token!="error"){
				if(type == "int"){

					SymbolInfo* s = new SymbolInfo($3->getName(), "int");
					s-> Token = "ID";
					if(table->Insert(s) == 0){
						yyerror("Multple declaration! ");
temp->Token="error";
					}
					else
					{
						temp->address=newAdd($3->name,table->id);
						declaration += temp->address+ " dw ?\n";
					}
				}
				if(type == "float"){
					SymbolInfo* s = new SymbolInfo($3->getName(), "float");
					s-> Token = "ID";
					if(table->Insert(s) == 0){
						yyerror("Multple declaration! ");
temp->Token="error";
					}
					else
					{
						temp->address=newAdd($3->name,table->id);
						declaration += temp->address+ " dw ?\n";
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
				if(debugging)fprintf(logout,"Line %d: declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD\n",line_count);
				if(debugging)fprintf(logout,"%s\n%d\n\n",$3->getName().c_str(),$5->ivalue);
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
					else
					{
						temp->address=newAdd($3->name,table->id);
						declaration += temp->address+ " dw ?";
						for(int i =0; i<$5->ivalue; i++){
							declaration += ", ?";
						}
						declaration +="\n";
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
					else
					{
						temp->address=newAdd($3->name,table->id);
						declaration += temp->address+ " dw ?";
						for(int i =0; i<$5->ivalue; i++){
							declaration += ", ?";
						}
						declaration +="\n";
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
				if(debugging)fprintf(logout,"Line %d: declaration_list : ID\n",line_count);
				if(debugging)fprintf(logout,"%s\n\n",$1->getName().c_str());
				cout<<"Line %d: declaration_list : ID\n";

SymbolInfo* temp = new SymbolInfo();

				if(type == "int"){
					SymbolInfo* s = new SymbolInfo($1->getName(), "int");
					s-> Token = "ID";
					if(table->Insert(s) == 0){
						yyerror("Multple declaration! ");
temp->Token="error";
					}
					else
					{
						cout<<"###1"<<endl;
						temp->address=newAdd($1->name,table->id);
						cout<<"###2"<<endl;
						declaration += temp->address+ " dw ?\n";
						cout<<"###3"<<temp->address<<endl;
					}
				}
				if(type == "float"){
					SymbolInfo* s = new SymbolInfo($1->getName(), "float");
					s-> Token = "ID";
					if(table->Insert(s) == 0){
						yyerror("Multple declaration! ");
temp->Token="error";
					}
					else
					{
						temp->address=newAdd($1->name,table->id);
						declaration += temp->address+ " dw ?\n";
					}
				}
				if(type == "void"){
					yyerror("A variable cannot be declared as void!");
temp->Token="error";
				}

$$=temp;
//cout<<"Code: "<<temp->code<<endl;
			}
		 | ID LTHIRD CONST_INT RTHIRD  {
				if(debugging)fprintf(logout,"Line %d: declaration_list : ID LTHIRD CONST_INT RTHIRD\n",line_count);
				if(debugging)fprintf(logout,"%s\n%d\n\n",$1->getName().c_str(),$3->ivalue);
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
s->array[i]=new SymbolInfo(s->name,"int");
}
					if(table->Insert(s) == 0){
						yyerror("Multple declaration! ");
temp->Token="error";
					}
					else
					{
						temp->address=newAdd($1->name,table->id);
						declaration += temp->address+ " dw ?";
						for(int i =0; i<$3->ivalue; i++){
							declaration += ", ?";
						}
						declaration +="\n";
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
					else
					{
						temp->address=newAdd($1->name,table->id);
						declaration += temp->address+ " dw ?";
						for(int i =0; i<$3->ivalue; i++){
							declaration += ", ?";
						}
						declaration +="\n";
					}
				}
				if(type == "void"){
					yyerror("A variable cannot be declared as void!");
temp->Token="error";
				}

$$=temp;
			}
		 ;

statements : statement  {
	if(debugging)fprintf(logout,"Line %d: statements : statement\n\n",line_count);
	cout<<"Line %d: statements : statement\n\n";
	$$=$1;
	cout<<"####1"<<$1->address<<endl;
 }
	   | statements statement  {
		   if(debugging)fprintf(logout,"Line %d: statements : statements statement\n\n",line_count);
		   cout<<"Line %d: statements : statements statement\n\n";
		   $$=$1;
		   cout<<"####1\n\n";
		   $$->code += $2->code;
		   //cout<<"####2\n\n"<<$$->code;
	   }
	   ;


statement  : var_declaration {
if(debugging)fprintf(logout,"Line %d: statement  : var_declaration\n\n",line_count);
$$=$1;
}
	   | expression_statement  {
		   if(debugging)fprintf(logout,"Line %d: statement : expression_statement\n\n",line_count);
		   $$=$1;
	   }
	   | compound_statement  {
		   if(debugging)fprintf(logout,"Line %d: statement : compound_statement\n\n",line_count);
		   $$=$1;
	   }
	   | FOR LPAREN expression_statement expression_statement expression RPAREN statement  {
		    if(debugging)fprintf(logout,"Line %d: statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n\n",line_count);
			$$=$3;
			char*  label1=newLabel();
		  	char*  label2=newLabel();

			$$->code += string(label1)+":\n";
			$$->code += $4->code;
			$$->code += "cmp "+ $4->address+", 1\n";
			$$->code += "jne "+string(label2)+"\n";
			$$->code += $7->code;
			$$->code += $5->code;
			$$->code +="jmp "+string(label1)+"\n";
			$$->code += string(label2)+":\n\n";
		}
	   | IF LPAREN expression RPAREN statement %prec only_if {
		    if(debugging)fprintf(logout,"Line %d: statement :  IF LPAREN expression RPAREN statement\n\n",line_count);
			$$=$3;

 			char*  label=newLabel();

			$$->code+="mov ax,"+  $3->address +"\n";
			$$->code+="cmp ax,0\n";
			$$->code+="je "+string(label)+"\n";
			$$->code+=$5->code;
			$$->code+=string(label)+":\n\n";
		 }
	   | IF LPAREN expression RPAREN statement ELSE statement {
		   if(debugging)fprintf(logout,"Line %d: statement : IF LPAREN expression RPAREN statement ELSE statement\n\n",line_count);
		   $$=$3;

		   char*  label1=newLabel();
		   char*  label2=newLabel();

		   $$->code+="mov ax,"+ $3->address +"\n";
		   $$->code+="cmp ax,0\n";
		   $$->code+="je "+string(label1)+"\n";
		   $$->code+=$5->code;
		   $$->code+="jmp " + string(label2)+"\n";
		   $$->code+=string(label1)+":\n";
		   $$->code+=$7->code;
		   $$->code+=string(label2)+":\n\n";
	    }
	   | WHILE LPAREN expression RPAREN statement  {
		    if(debugging)fprintf(logout,"Line %d: statement : WHILE LPAREN expression RPAREN statement\n\n",line_count);
			$$=new SymbolInfo();
			char* label1 = newLabel();
			char* label2 = newLabel();

			//$$->code += $3->code;
			$$->code += string(label1)+":\n";
			$$->code += $3->code;
			$$->code += "cmp "+ $3->address +",1\n";
			$$->code += "jne "+string(label2)+"\n";
			$$->code += $5->code;
			$$->code += "jmp "+string(label1)+"\n";
			$$->code += string(label2)+":\n\n";
		 }
	   | PRINTLN LPAREN ID RPAREN SEMICOLON  {
		   if(debugging)fprintf(logout,"Line %d: statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n\n",line_count);
		   $$=new SymbolInfo();
		   $$->code += $3->code;
		   SymbolInfo* temp = table->Lookup($3->getName());
		   if (temp == NULL){
			   yyerror("Undeclared variable "+$3->getName());
		   }
		   else {
			   $$->address=newAdd(temp->name,temp->id);
			   $$->code += "mov ax,"+$$->address+"\n";
			   $$->code += "call PRINTLN\n";
	   	  }
	   }
	   | RETURN expression SEMICOLON  {
		   if(debugging)fprintf(logout,"Line %d: statement : RETURN expression SEMICOLON \n\n",line_count);
		   // write code for return.
		   $$=$2;
		   $$->code+="mov ax,"+$2->address+"\n";
		   $$->code+="mov "+fn2->retaddress+",ax\n";
		   $$->address=fn2->retaddress;
		   cout<<"return ret: "<<$$->address<<endl;
	   }

	   | error SEMICOLON {
		   $$=new SymbolInfo();
	   	$$->name = ";";
	   	$$->Token = "error";
	   	$$->code="";
	   }
;

expression_statement	: SEMICOLON		 {
	if(debugging)fprintf(logout,"Line %d: expression_statement	: SEMICOLON\n\n",line_count);
	$$=new SymbolInfo();
	$$->name = ";";
	$$->Token = "SEMICOLON";
	$$->code="";
}
			| expression SEMICOLON  {
				if(debugging)fprintf(logout,"Line %d: expression_statement	: expression SEMICOLON\n\n",line_count);
				cout<<"Line %d: expression_statement: expression SEMICOLON\n\n";
 			 	$$=$1;
				//cout<<$$->code;
			 }
			;

variable : ID	{
			if(debugging)fprintf(logout,"Line %d: variable : ID\n",line_count);
			if(debugging)fprintf(logout,"%s\n\n",$1->getName().c_str());
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

			temp->address=newAdd(temp->name,temp->id);
			$$ = temp;
			cout<<"return Id : "<<$$->address<<endl;
		}
		| ID LTHIRD expression RTHIRD  {
			if(debugging)fprintf(logout,"Line %d: variable : ID LTHIRD expression RTHIRD\n",line_count);
			if(debugging)fprintf(logout,"%s\n\n",$1->getName().c_str());
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
					int size=temp->arraysize;
					int tid=temp->id;
					temp = temp->array[$3->ivalue];
					temp=new SymbolInfo(temp);
					temp->code=$3->code+"mov bx," +$3->address +"\nadd bx,bx\n";
					temp->address=newAdd(temp->name,tid);
					cout<<"Var address : "<<temp->name<<"  "<<tid<<"  "<<temp->address<<endl;
					temp->arraysize=size;
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
			if(debugging)fprintf(logout,"Line %d: expression : logic_expression\n\n",line_count);
			$$ = $1;
			cout<<"return le: "<<$$->address<<endl;
		}
	    | variable ASSINOP logic_expression 	 {
			if(debugging)fprintf(logout,"Line %d: expression : variable ASSINOP logic_expression\n\n",line_count);
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
			//table->PrintAllScopeTable();
		}
else {temp->Token="error";}

$$=temp;

	$$->code=$3->code+$1->code;
	$$->code+="mov ax,"+$3->address+"\n";
	if($1->arraysize==-1){
		$$->code+= "mov "+$1->address+",ax\n";
	}

	else{
		$$->code+= "mov "+$1->address+"[bx],ax\n";
	}
}

	   ;

logic_expression : rel_expression 	 {
			if(debugging)fprintf(logout,"Line %d: logic_expression : rel_expression\n\n",line_count);
			$$ = $1;
			cout<<"return re: "<<$$->address<<endl;
		}
		| rel_expression LOGICOP rel_expression 	 {
			if(debugging)fprintf(logout,"Line %d: logic_expression : rel_expression\n\n",line_count);
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

	$$->code=$1->code;
	$$->code+=$3->code;
	char *t=newTemp();

	declaration += string(t) + " dw ?\n";
	char *label1=newLabel();
	char *label2=newLabel();
	char *label3=newLabel();

	$$->code +="mov ax," + $1->address +"\n";
	$$->code +="mov bx," + $3->address +"\n";

	if($2->name == "&&"){
		$$->code += "cmp ax,0\nje "+string(label1)+"\ncmp bx,0\nje "+string(label1)+"\n";
		$$->code += string(label2)+":\nmov "+ string(t)+",1\njmp "+string(label3)+"\n";
		$$->code += string(label1)+":\nmov "+ string(t)+",0\n";
	}
	else if ($2->name == "||"){
		$$->code += "cmp ax,0\njne "+string(label1)+"\ncmp bx,0\njne "+string(label1)+"\n";
		$$->code += string(label2)+":\nmov "+ string(t)+",0\njmp "+string(label3)+"\n";
		$$->code += string(label1)+":\nmov "+ string(t)+",1\n";
	}
	$$->code += string(label3)+":\n";
	$$->address = string(t);

		}
		;

rel_expression	: simple_expression  {
			if(debugging)fprintf(logout,"Line %d: rel_expression : simple_expression\n\n",line_count);
			$$ = $1;
		}
		| simple_expression RELOP simple_expression	 {
			if(debugging)fprintf(logout,"Line %d: rel_expression : simple_expression RELOP simple_expression\n\n",line_count);
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
	$$->code=$1->code;
	$$->code+=$3->code;
	$$->code+="mov ax," + $1->address+"\n";
	$$->code+="cmp ax," + $3->address+"\n";
	char *t=newTemp();
	declaration += string(t) + " dw ?\n";
	char *label1=newLabel();
	char *label2=newLabel();
	if($2->name=="<"){
		$$->code+="jl " + string(label1)+"\n";
	}
	else if($2->name=="<="){
		$$->code+="jle " + string(label1)+"\n";
	}
	else if($2->name==">"){
		$$->code+="jg " + string(label1)+"\n";
	}
	else if($2->name==">="){
		$$->code+="jge " + string(label1)+"\n";
	}
	else if($2->name=="=="){
		$$->code+="je " + string(label1)+"\n";
	}
	else{
		$$->code+="jne " + string(label1)+"\n";
	}

	$$->code+="mov "+string(t) +",0\n";
	$$->code+="jmp "+string(label2) +"\n";
	$$->code+=string(label1)+":\nmov "+string(t)+",1\n";
	$$->code+=string(label2)+":\n";
	$$->address=string(t);

}


		;

simple_expression : term  {
			if(debugging)fprintf(logout,"Line %d: simple_expression : term\n\n",line_count);
			$$ = $1;
		}
		| simple_expression ADDOP term  {
			if(debugging)fprintf(logout,"Line %d: simple_expression : simple_expression ADDOP term\n\n",line_count);
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

$$->code = $1->code;
$$->code += $3->code;
char *t=newTemp();
declaration += string(t) + " dw ?\n";
if($2->name=="+"){
	$$->code += "mov ax," + $1->address + "\n";
	$$->code += "add ax," + $3->address + "\n";
	$$->code += "mov "+ string(t) + ",ax\n";
}
else {
	$$->code += "mov ax," + $1->address + "\n";
	$$->code += "sub ax," + $3->address + "\n";
	$$->code += "mov "+ string(t) + ",ax\n";
}
$$->address=string(t);

		}
		;

term :	unary_expression {
			if(debugging)fprintf(logout,"Line %d: term : unary_expression\n\n",line_count);
			$$ = $1;
			cout<<"return ue: "<<$1->address<<endl;
		}
     |  term MULOP unary_expression {
			if(debugging)fprintf(logout,"Line %d: term : term MULOP unary_expression\n\n",line_count);
						SymbolInfo* s = new SymbolInfo();
if($1->Token!="error" && $3->Token!="error"){

if(debugging)fprintf(logout,"%s\n\n",$2->name.c_str());
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

			//cout << endl << $$->code << endl;
			//delete $3;
}
else {s->Token="error";}

$$=s;
$$->code = $1->code;
$$->code += $3->code;
$$->code += "mov ax,"+ $1->address+"\n";
$$->code += "mov bx,"+ $3->address +"\n";
char *t=newTemp();
declaration += string(t) + " dw ?\n";
if($2->name=="*"){
	$$->code += "mul bx\n";
	$$->code += "mov "+ string(t) + ",ax\n";
}
else if($2->name=="/"){
	// clear dx, perform 'div bx' and mov ax to temp
	$$->code += "mov dx,0\n";
	$$->code += "div bx\n";
	$$->code += "mov "+string(t)+",ax\n";
}
else{
	// clear dx, perform 'div bx' and mov dx to temp
	$$->code += "mov dx,0\n";
	$$->code += "div bx\n";
	$$->code += "mov "+string(t)+",dx\n";
}
$$->address=string(t);
		}
     ;

unary_expression : ADDOP unary_expression   {
				if(debugging)fprintf(logout,"Line %d: unary_expression : ADDOP unary_expression\n\n",line_count);
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
					temp->code=$2->code;
					char *t=newTemp();
					declaration += string(t) + " dw ?\n";
					temp->code+="mov ax," + $2->address + "\n";
					temp->code+="neg ax\n";
					temp->code+="mov "+string(t)+",ax";
					temp->address=string(t);

				}

}
else {temp->Token="error";}
$$=temp;
}
		 | NOT unary_expression  {
if(debugging)fprintf(logout,"Line %d: unary_expression : NOT unary_expression\n\n",line_count);
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
				temp->code=$2->code;
				char *t=newTemp();
				char *label1=newLabel();
				char *label2=newLabel();
				declaration += string(t) + " dw ?\n";
				temp->code+="mov ax," + $2->address + "\n";
				temp->code+="cmp ax,0\n";
				temp->code+="je " + string(label1) + "\nmov " + string(t) +",0\njmp " + string(label2)+"\n";
				temp->code+=string(label1)+":\nmov "+string(t) + ",1\n" + string(label2) + ":\n";
				temp->address=string(t);

}
else {temp->Token="error";}

				$$ = temp;
			}
		 | factor  {
				if(debugging)fprintf(logout,"Line %d: unary_expression : factor\n\n",line_count);
				$$ = $1;
			}
		 ;

factor	: variable  {
			if(debugging)fprintf(logout,"Line %d: factor : variable\n\n",line_count);
			$$=$1;

			if($$->arraysize==-1){

			}
			else{
				char *t= newTemp();
				declaration += string(t) + " dw ?\n";
				$$->code+="mov ax," + $1->address + "[bx]\n";
				$$->code+= "mov " + string(t) + ",ax\n";
				$$->address=string(t);
			}
			cout<<"return var: "<<$$->address<<endl;
		}
	| ID LPAREN argument_list RPAREN {

if(debugging)fprintf(logout,"Line %d: factor : ID LPAREN argument_list RPAREN\n\n",line_count);

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
	si->code=$3->code;
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
		si->code+="push "+args[i].address+"\n";

	}
si->code+="call "+$1->name+"\n";
if(s->fp->retaddress!="")si->address=s->fp->retaddress;

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
			if(debugging)fprintf(logout,"Line %d: factor :  LPAREN expression RPAREN\n\n",line_count);
			$$ = $2;
		}
	| CONST_INT  {
			if(debugging)fprintf(logout,"Line %d: factor : CONST_INT\n",line_count);
			if(debugging)fprintf(logout,"%d\n\n",$1->ivalue);
			$$ = $1;
			char *t= newTemp();
			declaration += string(t) + " dw ?\n";
			ostringstream oss;
			oss<<"mov " + string(t) + ","<<$1->ivalue<<endl;
			$$->code+=oss.str();
			$$->address=string(t);
		}
	| CONST_FLOAT {
			if(debugging)fprintf(logout,"Line %d: factor : CONST_FLOAT\n",line_count);
			if(debugging)fprintf(logout,"%lf\n\n",$1->fvalue);
			$$ = $1;
			char *t= newTemp();
			declaration += string(t) + " dw ?\n";
			ostringstream oss;
			oss<<"mov " + string(t) + ","<<(int)$1->fvalue<<endl;
			$$->code+=oss.str();
			$$->address=string(t);
		}
	| variable INCOP  {
if($1->Token!="error")
{
			if(debugging)fprintf(logout,"Line %d: factor : variable INCOP\n\n",line_count);
			if(type == "int"){
				$1->ivalue++;
			}
			else if(type == "float"){
				$1->fvalue++;
			}
			$1->code += "INC " + $1->address + "\n";
}
$$=$1;
}
	| variable DECOP {
if($1->Token!="error")
{
			if(debugging)fprintf(logout,"Line %d: factor : variable DECOP\n\n",line_count);
			if(type == "int"){
				$1->ivalue--;
			}
			else if(type == "float"){
				$1->fvalue--;
			}
			$1->code += "DEC " + $1->address + "\n";

}
$$=$1;
}
	;

argument_list : arguments {
if(debugging)fprintf(logout,"Line %d: argument_list : argumets\n\n",line_count);
$$=$1;
}
                    | {
if(debugging)fprintf(logout,"Line %d: argument_list : empty\n\n",line_count);
$$= new SymbolInfo();
}
                    ;


arguments : arguments COMMA logic_expression
{
if(debugging)fprintf(logout,"Line %d: argument_list : argument_list COMMA logic_expression\n\n",line_count);
if($1->Token!="error" && $3->Token!="error"){
args.push_back(*($3));
$$= new SymbolInfo();
}
else if($1->Token=="error")$$=$1;
else $$=$3;

$$->code=$1->code+$3->code;
}
	      | logic_expression
{
	if(debugging)fprintf(logout,"Line %d: argument_list : logic_expression\n\n",line_count);

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
	optimized= fopen("optimized.asm","w");
	//error= fopen("error.txt","w");
	//symtable= fopen("symtable.txt","w");

	yyin= fin;
	yyparse();
	fclose(yyin);
	fclose(logout);
	//fclose(error);
	//fclose(symtable);
	return 0;
}

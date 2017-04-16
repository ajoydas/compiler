
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

			 
type_specifier	: INT  { fprintf(logout,"Line No. %d: type_specifier : INT \n\n",line_count); type="int"; $$=new SymbolInfo("int","type"); }
		| FLOAT { fprintf(logout,"Line No. %d: type_specifier : FLOAT\n\n",line_count); type="float";$$=new SymbolInfo("float","type"); }
		| VOID { fprintf(logout,"Line No. %d: type_specifier : VOID\n\n",line_count); type="void";$$=new SymbolInfo("void","type"); }
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


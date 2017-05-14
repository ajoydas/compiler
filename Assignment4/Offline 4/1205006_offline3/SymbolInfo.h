#include <bits/stdc++.h>
using namespace std;

class SymbolInfo{
public:
    string Name;
    string Token;
    string code = "";
	double dvalue;
	float fvalue;
	//string svalue = "";
	char c;
	int ivalue;
	//string svalue;
	string datatype;
	SymbolInfo* next;
	SymbolInfo** array;
	int arraysize = -1;
	string arrIndexHolder="";

	SymbolInfo(){

	}

    SymbolInfo(string name, string type){
        Name = name;
        datatype = type;
        /*if(type == "CONST_INT") datatype = "int";
        else if(type == "CONST_CHAR") datatype = "char";
        else if(type == "CONST_float") datatype = "float";*/
    }
	
	SymbolInfo(SymbolInfo* s){
		Name = s->Name;
		Token = s->Token;
		code = s->code;
		dvalue = s->dvalue;
		fvalue = s->fvalue;
		c = s->c;
		ivalue = s->ivalue;
		datatype = s->datatype;
		arraysize = s->arraysize;
		arrIndexHolder = s->arrIndexHolder;
	}
};

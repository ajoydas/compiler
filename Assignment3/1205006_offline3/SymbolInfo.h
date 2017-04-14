#include <bits/stdc++.h>
using namespace std;

class SymbolInfo{
public:
    string Name;
    string Token;
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
	
	SymbolInfo(){
		
	}

    SymbolInfo(string name, string type){
        Name = name;
        datatype = type;
    } 
};

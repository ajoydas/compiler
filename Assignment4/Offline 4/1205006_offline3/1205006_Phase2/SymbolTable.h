#include <bits/stdc++.h>
#include "SymbolInfo.h"
using namespace std;


//ofstream f1out ("outputfile.txt");
ofstream tout ("log.txt");

class SymbolTable{
public:
    int NUM;
	vector< vector<SymbolInfo* > > table;
	
    SymbolTable(int n){
        NUM = n;
        for(int i = 0; i < n; i++){
            vector<SymbolInfo*> temp;
            table.push_back(temp);
        }
    }
    

    int hash(string str3){
        char arr[str3.size()];
        strcpy(arr, str3.c_str());
        int h=0;
        char* c;
        c = arr;
        while(*c){
            int temp = *c++;
            h *=100;
            h += temp;
        }

        h = abs(h);
        return h;
    }

    int insert(SymbolInfo* s){
		string name = s->Name;
		string type = s->datatype;
        int temp = hash(name);
        int pos = temp%NUM;
        int listSize = table[pos].size();

        for(int i = 0; i < table[pos].size(); i++){
            if(name.compare(table[pos][i]->Name)==0){
                tout<<" <"<<table[pos][i]->Name<<" "<<table[pos][i]->datatype<<"> "\
                <<"Already exists at "<<pos<<", "<<i<<endl;
                return -1;
            }
        }

		if(s->arraysize > 0){
			s->array = new SymbolInfo*[s->arraysize];
			for(int i = 0; i< s->arraysize; i++){
				s->array[i] = new SymbolInfo();
				s->array[i]->datatype = s->datatype;
			}
		}
        table[pos].push_back(s);

        tout<<" <"<<name<<", "<<type<<"> "<<"Inserted at position "<<pos<<", "<<listSize<<endl;
		if(s->arraysize > 0){
			tout<<"Array size: "<<s->arraysize <<endl;
		}
    }

    SymbolInfo* searchTable (string name){
        int pos = hash(name)%NUM;
        for(int i = 0; i < table[pos].size(); i++){
            if(name.compare(table[pos][i]->Name)==0){
                tout<<"Item <"<<table[pos][i]->Name<<", "<<table[pos][i]->datatype<<"> "\
                <<"Found at "<<pos<<", "<<i<<endl;
                return table[pos][i];
            }
        }
        tout<<"Item <"<<name<<"> "<<"Not found!"<<endl;
        return 0;
    }

    void searchByType (string str3){
        //int pos = hash(str3)%NUM;
        tout<<"Items of type "<<str3<<":"<<endl<<"---------------------\n";
        for(int j =0; j<NUM; j++){
            for(int i = 0; i < table[j].size(); i++){
                if(str3.compare(table[j][i]->datatype)==0){
                    tout<<"< "<<table[j][i]->Name<<" > at "<<j<<" "<<i<<endl;
                }
            }
        }
//        tout<<"No item of this type found!"<<endl;
//        return;
    }

    void printTable(ofstream& f1out)
    {
        f1out<<endl;
        for(int i = 0; i<NUM; i++){
            f1out<<i<<"->";
            for(int j = 0; j< table[i].size(); j++){
                f1out<<" <"<<table[i][j]->Name<<", "<<table[i][j]->datatype<<" ";
				if(table[i][j]->arraysize > 0){
					f1out<<", { ";
					for(int k = 0; k < table[i][j]->arraysize; k++){
						if(table[i][j]->datatype == "int") f1out<<table[i][j]->array[k]->ivalue <<", ";
						else if(table[i][j]->datatype == "char") f1out<<table[i][j]->array[k]->c <<", ";
						if(table[i][j]->datatype == "float") f1out<<table[i][j]->array[k]->fvalue <<", ";
					}
					f1out<<" }";
				}
				else {
					f1out<<", ";
					if(table[i][j]->datatype == "int") f1out<<table[i][j]->ivalue <<", ";
					else if(table[i][j]->datatype == "char") f1out<<table[i][j]->c <<", ";
					if(table[i][j]->datatype == "float") f1out<<table[i][j]->fvalue <<", ";
				}
				f1out<<"> "<<" ->";
            }
            f1out<<endl;
        }
        f1out<<endl;
    }

    void printThis(string s, int i){
        tout<<s<<i<<endl;
    }

    void Delete(string str2){
        int pos = hash(str2)%NUM;
        for(int i = 0; i < table[pos].size(); i++){
            if(str2.compare(table[pos][i]->Name)){
                tout<<"Deleted "<<" <"<<table[pos][i]->Name<<", "<<table[pos][i]->datatype<<"> "\
                <<" from "<<pos<<", "<<i<<endl;
                table[pos].erase(table[pos].begin()+i);
                return ;
            }
        }
        tout<<"Item <"<<str2<<"> "<<"Not found! Cannot delete."<<endl;
        return;
    }
};

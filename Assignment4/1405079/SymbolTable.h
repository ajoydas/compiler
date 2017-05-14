#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <bits/stdc++.h>
#define MAXRANGE 100
using namespace std;

extern FILE *logout;
extern FILE *symtable;
extern bool symtabprint;
class SymbolInfo;
class Function
{
public:
	string retype;
	vector<SymbolInfo> params;
};

class SymbolInfo
{
public:
	string name;
    string type;
		string code;
		string address;
	string Token;
    SymbolInfo* next;
	int ivalue;
	float fvalue;
	Function *fp;
	SymbolInfo** array;
	int arraysize = -1;

    SymbolInfo()
    {
        this->name = "";
        this->type = "";
				this->code = "";
        this->address = "";
		ivalue=-1e+007;
		fvalue=-1e+007;
        this->next = NULL;
		this->fp=NULL;
		this-> array=NULL;

    }

    SymbolInfo(string name,string type,SymbolInfo* next=NULL) {
        this->name = name;
        this->type = type;
        this->next = next;
				this->code = "";
        this->address = "";
				ivalue=-1e+007;
				fvalue=-1e+007;
		        this->next = NULL;
				this->fp=NULL;
				this-> array=NULL;
    }

	SymbolInfo(SymbolInfo *s)
    {
        this->name = s->name;
        this->type = s->type;
		this->code = s->code;
        this->address = s->address;
		this->ivalue=s->ivalue;
		this->fvalue=s->fvalue;
        this->next = s->next;
		this->fp=s->fp;
		this-> array=s-> array;

    }

    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        SymbolInfo::name = name;
    }

    const string &getType() const {
        return type;
    }

    void setType(const string &type) {
        SymbolInfo::type = type;
    }

void Print()
{
cout<<"<--------Symbol Info:------>\n"<<"Name : "<<name<<endl;
cout<<"Type : "<<type<<endl;
cout<<"Code : "<<code<<endl;
cout<<"Address : "<<address<<endl;
cout<<"Ivalue : "<<ivalue<<endl;
cout<<"Fvalue : "<<fvalue<<endl;
cout<<"ArraySize : "<<arraysize<<endl;
if(fp!=NULL)
{
cout<<"Function :"<<endl;
cout<<"Return Type: "<<fp->retype<<endl;
cout<<"Params : start\n";
for(int i=0;i<fp->params.size();i++)
{
cout<<fp->params[i].getName()<<" "<<fp->params[i].getType()<<endl;
}
cout<<"Params : end\n";
}
}
};



class ScopeTable
{
public:
    int n;
    int id;
    SymbolInfo** arr;
    ScopeTable* parentScope;
    ScopeTable(int n,int id)
    {
        this->n=n;
        this->id=id;
        this->parentScope=NULL;
        arr= new SymbolInfo*[n];
        for (int i = 0; i < n; ++i) {
            arr[i] = new SymbolInfo;
        }
    }
    void FreeSpace()
    {
	//cout<<"Freeing space"<<endl;
	for (int i = 0; i < n; ++i) {
            SymbolInfo *currSymbol = arr[i];
            while (currSymbol != NULL) {
                SymbolInfo *temp=currSymbol;
                currSymbol = currSymbol->next;
                delete(temp);
            }
        }
    }
    bool Insert(SymbolInfo& symbol)
    {
        int pos=hashing(symbol.getName(),n);
        if(arr[pos]->next==NULL)
        {
            //cout<<"Inserted in ScopeTable# "<<id<<" at position "<<pos<<"," <<0<<endl;
			SymbolInfo *temp=new SymbolInfo(symbol.getName(),symbol.getType());
			temp->code=symbol.code;
			temp->address=symbol.address;
			temp->ivalue=symbol.ivalue;
			temp->fvalue=symbol.fvalue;
			temp->Token=symbol.Token;
			temp->arraysize=symbol.arraysize;
			temp->array=symbol.array;
			temp->fp=symbol.fp;
            arr[pos]->next=temp;
	    //Print();
            return true;
        }
        else
        {
            int count=0;
            SymbolInfo *currSymbol = arr[pos];
            while (currSymbol->next != NULL) {
                if (currSymbol->next->getName() == symbol.getName()) {
                    //cout <<"<"<<symbol.getName()<<","<<symbol.getType()<<">"<<" already exists in current ScopeTable"<<endl;
		    //fprintf(logout,"<%s,%s> already exists\n",symbol.getName().c_str(),symbol.getType().c_str());
                    return false;
                }
                currSymbol = currSymbol->next;
                count++;
            }
            //cout<<"Inserted in ScopeTable# "<<id<<" at position "<<pos<<"," <<count+1<<endl;
			SymbolInfo *temp=new SymbolInfo(symbol.getName(),symbol.getType());
			temp->code=symbol.code;
			temp->address=symbol.address;
			temp->ivalue=symbol.ivalue;
			temp->fvalue=symbol.fvalue;
			temp->Token=symbol.Token;
			temp->arraysize=symbol.arraysize;
			temp->array=symbol.array;
			temp->fp=symbol.fp;
            currSymbol->next=temp;
	    //Print();
            return true;
        }

    }

    SymbolInfo *LookUp(string name)
    {
        int pos=hashing(name,n);
        if(arr[pos]->next==NULL)return NULL;
        else
        {
            int count=0;
            SymbolInfo *currSymbol=arr[pos]->next;
            while(currSymbol!=NULL)
            {
                //cout<<currSymbol->getName()<<" ";
                if(currSymbol->getName()==name) {
                    cout<<"Found in ScopeTable# "<<id<<" at position "<<pos<<"," <<count<<endl;
                    return currSymbol;
                }
                count++;
                currSymbol=currSymbol->next;
            }
            return NULL;
        }
    }

    bool Delete(string name)
    {
        if(LookUp(name) == NULL)
        {
            cout<<"Not Found"<<endl;
            return false;
        }
        int pos=hashing(name,n);
        int count=0;
        SymbolInfo *currSymbol = arr[pos];
        while (currSymbol->next != NULL) {
            if(currSymbol->next->getName()==name)
            {
                SymbolInfo *temp=currSymbol->next;
                currSymbol->next= currSymbol->next->next;
                delete(temp);
                cout<<"Deleted entry at "<<pos<<", "<<count <<" from current ScopeTable"<<endl;
                return true;
            }
            currSymbol = currSymbol->next;
            count++;
        }
        return false;
    }
    void Print()
    {
        fprintf(logout,"ScopeTable # %d\n",id);
        if(symtabprint)fprintf(symtable,"ScopeTable # %d\n",id);
        for (int i = 0; i < n; ++i) {
            SymbolInfo *currSymbol=arr[i]->next;
    	    if(currSymbol == NULL)continue;
    	    fprintf(logout,"%d --> ",i);
            if(symtabprint) fprintf(symtable,"%d --> ",i);
            while (currSymbol != NULL) {
                fprintf(logout," < %s, %s ",currSymbol->getName().c_str(),currSymbol->getType().c_str());
                if(symtabprint)fprintf(symtable," < %s, %s ",currSymbol->getName().c_str(),currSymbol->getType().c_str());
                cout<<"Arraysize: "<<currSymbol->arraysize<<endl;
        		if(currSymbol->arraysize!=-1)
        		{
                    fprintf(logout,",{ ");
                    if(symtabprint)fprintf(symtable,",{ ");
                    for(int i=0;i<currSymbol->arraysize;i++)
                    {
                        if(currSymbol->type=="int"){
                            fprintf(logout,"%d",currSymbol->array[i]->ivalue);
                            if(symtabprint)fprintf(symtable,"%d",currSymbol->array[i]->ivalue);
                        }
                        else if(currSymbol->type=="float")
                        {
                            fprintf(logout,"%f",currSymbol->array[i]->fvalue);
                            if(symtabprint)fprintf(symtable,"%f",currSymbol->array[i]->fvalue);
                        }
						if(i!=currSymbol->arraysize-1)
						{
							fprintf(logout,", ");
                            if(symtabprint)fprintf(symtable,", ");
						}
                    }
                    fprintf(logout," }>");
                    if(symtabprint)fprintf(symtable," }>");
    			}
                else if(currSymbol->fp!=NULL){
                    fprintf(logout,">");
                    if(symtabprint)fprintf(symtable,">");
                }
                else if(currSymbol->type=="int"){
                    fprintf(logout,", %d >",currSymbol->ivalue);
                    if(symtabprint)fprintf(symtable,", %d >",currSymbol->ivalue);
                }
                else if(currSymbol->type=="float"){
                    fprintf(logout,", %f >",currSymbol->fvalue);
                    if(symtabprint)fprintf(symtable,", %f >",currSymbol->fvalue);
                }

                currSymbol = currSymbol->next;
            }
            fprintf(logout,"\n");
            if(symtabprint)fprintf(symtable,"\n");
        }
	fprintf(logout,"\n");
    if(symtabprint)fprintf(symtable,"\n");
    }
    void DistType()
    {
        vector<pair<string,int> >v=vector<pair<string,int> >();
         for (int i = 0; i < n; ++i) {

            SymbolInfo *currSymbol=arr[i]->next;
            while (currSymbol != NULL) {
                    bool flag=true;
            for(int j=0;j<v.size();j++)
            {
                if(v[j].first== currSymbol->getType())
                {
                    v[j].second++;
                    flag=false;
                }
            }
            if(flag)
            {
                v.push_back(make_pair(currSymbol->getType(),1));
            }

                currSymbol = currSymbol->next;

        }
    }
    cout<<"Printing type nums"<<endl;
     for(int j=0;j<v.size();j++)
            {
                cout<<v[j].first<<" "<<v[j].second<<endl;
            }
    }

int hashFunction(int x)
{
    return (3*pow(x,4)+11*pow(x,3)+19*x);
}

int hashing(string tempString,int max)
{
    int length=tempString.size(),hashCode=0;
    for (int i = 0; i < length; ++i) {
        hashCode+=(hashFunction(tempString[i]))%max;
        hashCode=(hashFunction(hashCode))%max;
    }
    return hashCode;
}

};

class SymbolTable
{
public:
    ScopeTable *currScope;
	int id=0;
    SymbolTable(int n,int id)
    {
        currScope=new ScopeTable(n,id);
		this->id=id;
    }
    void EnterScope()
    {
		id++;
        ScopeTable* temp=new ScopeTable(currScope->n,id);
        temp->parentScope=currScope;
        currScope=temp;
        cout<<"New ScopeTable with id "<<currScope->id<<" created"<<endl;
    }

    void ExitScope()
    {
        ScopeTable* temp=currScope;
        currScope=currScope->parentScope;
        cout<<"ScopeTable with id "<<temp->id<<" removed"<<endl;
        temp->FreeSpace();
        delete(temp);
    }
    void FreeSpace()
    {
	ScopeTable* temp=currScope;
        while (currScope!=NULL)
        {
            currScope=currScope->parentScope;
	    temp->FreeSpace();
        }

    }
    bool Insert(string name,string type)
    {
	SymbolInfo symbol(name,type);
        return currScope->Insert(symbol);
    }

	bool Insert(SymbolInfo *symbol)
    {
		//SymbolInfo symbol= *s;
        return currScope->Insert(*symbol);
    }

    bool Remove(string name)
    {
        return currScope->Delete(name);
    }

    SymbolInfo* Lookup(string name)
    {
        ScopeTable* temp=currScope;
        while (temp!=NULL)
        {
            SymbolInfo *res=temp->LookUp(name);
            if(res!=NULL)return res;
            temp=temp->parentScope;
        }
        return NULL;
    }
    void DistType()
    {
        currScope->DistType();
    }
    void PrintCurrentScopeTable()
    {
        cout<<"printing....";
        currScope->Print();
    }
    void PrintAllScopeTable()
    {
        ScopeTable* temp=currScope;
        while (temp!=NULL)
        {
            temp->Print();
            temp=temp->parentScope;
        }
    }

};

#endif

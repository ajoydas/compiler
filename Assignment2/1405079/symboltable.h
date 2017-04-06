#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <bits/stdc++.h>
#define MAXRANGE 100
using namespace std;

extern FILE *logout;

class SymbolInfo
{
private:
    string name;
    string type;
public:
    SymbolInfo* next;
    SymbolInfo()
    {
        this->name = "";
        this->type = "";
        this->next = NULL;
    }

    SymbolInfo(string name,string type,SymbolInfo* next=NULL) {
        this->name = name;
        this->type = type;
        this->next = next;
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
};

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
            arr[pos]->next=new SymbolInfo(symbol.getName(),symbol.getType());
	    Print();
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
            currSymbol->next=new SymbolInfo(symbol.getName(),symbol.getType());
	    Print();
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
        for (int i = 0; i < n; ++i) {
            SymbolInfo *currSymbol=arr[i]->next;
	    if(currSymbol == NULL)continue;
	    fprintf(logout,"%d --> ",i);
            while (currSymbol != NULL) {
                fprintf(logout," < %s, %s> ",currSymbol->getName().c_str(),currSymbol->getType().c_str());
                currSymbol = currSymbol->next;
            }
            fprintf(logout,"\n");
        }
	fprintf(logout,"\n");
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
};

class SymbolTable
{
public:
    ScopeTable *currScope;
    SymbolTable(int n,int id)
    {
        currScope=new ScopeTable(n,id);
    }
    void EnterScope()
    {
        ScopeTable* temp=new ScopeTable(currScope->n,currScope->id+1);
        temp->parentScope=currScope;
        currScope=temp;
        cout<<"New ScopeTable with id "<<currScope->id<<" created"<<endl;
    }

    void ExitScope()
    {
        ScopeTable* temp=currScope;
        currScope=currScope->parentScope;
        cout<<"ScopeTable with id "<<temp->id<<" removed"<<endl;
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

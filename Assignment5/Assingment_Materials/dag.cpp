#ifndef DAG_INCLUDED
#define DAG_INCLUDED
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class DAG_Node{
	string label;
	int lChild;
	int rChild;
public:
	DAG_Node(){
		//write code here
	}
	DAG_Node(string label, int l, int r){
		//write code here
		this->label=label;
		this->lChild=l;
		this->rChild=r;

	}
	~DAG_Node(){
		//Write Code Here
	}
	//Getter and Setter
	void setLabel(string label)
	{
		this->label=label;
	}
	string getLabel()
	{
		return this->label;
	}

	void setlChild(int l)
	{
		this->lChild=l;
	}
	int getlChild()
	{
		return this->lChild;
	}

	void setrChild(int r)
	{
		this->rChild=r;
	}
	int getrChild()
	{
		return this->rChild;
	}
};

int currIndex=1; // Current entry in dag_array will be at currIndex
DAG_Node dag_array[1000]; // Start from index 1
unordered_map<string, int> hashTable;
extern FILE *out;

int constructNode(string label, int l, int r){
	// Write code to implement value number method
	// You can Declare additional global variables and functions
	// You have to do hashing instead of searching linearly in the dag_array
	// STL can be used

	string input=label+"_"+to_string(l)+"_"+to_string(r);
	//cout<<"finding "<<input<<endl;
	unordered_map<string,int>::const_iterator got = hashTable.find (input);

  	if ( got != hashTable.end() ){
		//cout<<"Found at "<<got->second<<endl;
    	return got->second;
	}
	else
	{
		//cout<<"inserting "<<input<<endl;
		hashTable[input]=currIndex;
		dag_array[currIndex].setLabel(label);
		dag_array[currIndex].setlChild(l);
		dag_array[currIndex].setrChild(r);
		currIndex++;
		return currIndex-1;
	}

}

void print_dag_array(){
	// write code for printing a all entries of dag_array
	// you should print exactly in the way shown in sample output
	//cout << "DAG ARRAY" <<endl<<endl;
	fprintf(out,"DAG ARRAY\n\n");

	for(int i=1;i<currIndex;i++)
	{
		//cout<<i<<"--> "<<dag_array[i].getLabel()<<" "<<dag_array[i].getlChild()<<" "<<dag_array[i].getrChild()<<endl;
		fprintf(out,"%d --> %s %d %d\n",i,dag_array[i].getLabel().c_str(),dag_array[i].getlChild(),dag_array[i].getrChild());

	}
	//cout<<endl<<endl;
	fprintf(out,"\n\n");
}

void construct_tac(){
	// write code to construct and print three address code generated from dag
	// you should print exactly in the way shown in sample output
	//cout << "THREE ADDRESS CODE" <<endl<<endl;
	fprintf(out,"THREE ADDRESS CODE\n\n");

	string arr[1000];
	int tempcount=1;
	for(int i=1;i<currIndex;i++)
	{
		if(dag_array[i].getlChild()==0 && dag_array[i].getrChild()==0)
		{
			arr[i]=dag_array[i].getLabel();
		}
		else
		{
			string temp="t"+to_string(tempcount);
			//cout<<temp<<" = "<<arr[dag_array[i].getlChild()]<<" "<<dag_array[i].getLabel()<<" "<<arr[dag_array[i].getrChild()]<<endl;
			fprintf(out,"%s = %s %s %s\n",temp.c_str(),arr[dag_array[i].getlChild()].c_str(),dag_array[i].getLabel().c_str(),arr[dag_array[i].getrChild()].c_str());

			arr[i]=temp;
			tempcount++;

		}

	}
	//cout<<endl<<endl;
	fprintf(out,"\n\n");
}

#endif

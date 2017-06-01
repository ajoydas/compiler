#ifndef DAG_INCLUDED
#define DAG_INCLUDED
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class DAG_Node{

public:
	string label;
	int lChild;
	int rChild;
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
};

int currIndex=1; // Current entry in dag_array will be at currIndex
DAG_Node dag_array[1000]; // Start from index 1
unordered_map<string, int> hashTable;

int constructNode(string label, int l, int r){
	// Write code to implement value number method
	// You can Declare additional global variables and functions
	// You have to do hashing instead of searching linearly in the dag_array
	// STL can be used

	string input=label+"_"+to_string(l)+"_"+to_string(r);
	cout<<"finding "<<input<<endl;
	unordered_map<string,int>::const_iterator got = hashTable.find (input);

  	if ( got != hashTable.end() ){
		cout<<"Found at "<<got->second<<endl;
    	return got->second;
	}
	else
	{
		cout<<"inserting "<<input<<endl;
		hashTable[input]=currIndex;
		dag_array[currIndex].label=label;
		dag_array[currIndex].lChild=l;
		dag_array[currIndex].rChild=r;
		currIndex++;
		return currIndex-1;
	}

}

void print_dag_array(){
	// write code for printing a all entries of dag_array
	// you should print exactly in the way shown in sample output
	cout << "DAG ARRAY" <<endl;
	for(int i=1;i<currIndex;i++)
	{
		cout<<i<<"--> "<<dag_array[i].label<<" "<<dag_array[i].lChild<<" "<<dag_array[i].rChild<<endl;
	}
}

void construct_tac(){
	// write code to construct and print three address code generated from dag
	// you should print exactly in the way shown in sample output
	cout << "THREE ADDRESS CODE" <<endl;
	string arr[1000];
	int tempcount=1;
	for(int i=1;i<currIndex;i++)
	{
		if(dag_array[i].lChild==0 && dag_array[i].rChild==0)
		{
			arr[i]=dag_array[i].label;
		}
		else
		{
			string temp="t"+to_string(tempcount);
			cout<<temp<<" = "<<arr[dag_array[i].lChild]<<" "<<dag_array[i].label<<" "<<arr[dag_array[i].rChild]<<endl;
			arr[i]=temp;
			tempcount++;

		}

	}

}

#endif

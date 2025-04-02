#include<iostream>
using namespace std; 

class emp
{
 char data;
 emp *LC, *RC;
 public:
 	void create();
 	void insert ( emp *root, emp *next);
 	void display();
} *root;

void emp :: create()
{
	emp *next;
	int ch;
	root = new emp;
	cout <<"Enter the data";
	cin>> root->data;
	
	root->LC = root ->RC = NULL;
	do 
	{ 
	cout<<"Do you want to add ";
	cin>>ch;
	if(ch==1)
	{
	next= new emp;
	cout<<"Enter into next:";
	cin>>next->data;
	next-> LC = next-> RC = NULL;
	insert(root, next);
	}
	}
	while(ch==1);
	}

void emp :: insert( emp *root, emp *next)
{
char ch;
}

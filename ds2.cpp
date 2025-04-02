#include<iostream>
using namespace std;

class RRS 
{
	string name, address , adhar;
	int price;
	RRS *LC, *RC; 
	public :
	void create();
	void insert(RRS *root, RRS *next);
	void display(RRS *root);
}*root,  *st[10];

void RRS :: create()
{
	int ch ;
	RRS *next;
	root = new RRS;
	cout<<"Enter the Passenger's information";
	cin>> root->name>>root->adhar>>root->address>>root->price;
	root->LC = root->RC = NULL;
	do
	{
	 cout<<"Do you want to add data";
	 cin>>ch;
	 if(ch==1)
	 {
	 next = new RRS;
	 cout<<"Enter new information";
	 cin>> next->name >> next->address >>next->adhar>> next->price;
	 next->LC = next->RC =NULL;
	 insert(root, next);
	 }
	 }
	 while(ch==1);
}


void RRS :: insert(RRS *root , RRS *next)
{
	if(root->price > next->price)
	{
		if (root->LC == NULL) 
		{
			root->LC =next;
		}
		else
		{
			insert(root->LC, next);
		}
	}
	else if(root->price > next->price)
	{
		if (root->RC == NULL) 
		{
			root->RC =next;
		}
		else
		{
			insert(root->RC, next);
		}
	}
}

void RRS :: display(RRS *root)
{
	if(root == NULL)
	return;
	else
	{
	display(root->LC);
	cout<<"\n"<< root-> name << "\t" << root-> address <<"\t" << root-> adhar << "\t"<< root-> price ;
	display(root-> RC);
	}
}


int main()
{
RRS r;
int choice, i ;
do
{	cout<<"\n Railway Reservation System";
	cout<<"\n"<<"1.create " << "\n"<<"2.display";
	cout<<"\nEnter your choice";
	cin>> choice;
	switch(choice)
	{
	case 1:  r.create();
		break;
	case 2:  cout<<"\n"<<"Name"<<"\t"<<"Address"<<"\t"<<"Adhar" <<"\t"<< "price" ;
	               r.display( root);
		break;
	}
	cout<<"\nDo you want to continue";
	cin>>i;
} while(i==1);
return 0;
}

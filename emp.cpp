#include<iostream>
using namespace std;

class Emp
{
	int id, salary;
	int leaf=0;
	string name, address;
	Emp *LC, *RC;
	public :
	void create();
	void insert(Emp *root, Emp *next);
	void display(Emp *root);
}*root,  *st[10];

void Emp :: create()
{
	int ch ;
	Emp *next;
	root = new Emp;
	cout<<"Enter the employee information";
	cin>> root->id >> root->name >>root->salary>>root->address;
	root->LC = root->RC = NULL;
	do
	{
	 cout<<"Do you want to add data";
	 cin>>ch;
	 if(ch==1)
	 {
	 next = new Emp;
	 cout<<"Enter new information";
	 cin>> next->id >> next->name >>next->salary>> next->address;
	 next->LC = next->RC =NULL;
	 insert(root, next);
	 }
	 }
	 while(ch==1);
}


void Emp :: insert(Emp *root , Emp *next)
{
	char chr;
	cout<<"Where you want to insert " << root->id << "\t L or R ";
	cin>> chr;
	if(chr == 'L' ||  chr == 'l')
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
	else if(chr == 'R' || chr == 'r')
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

/*void Emp :: display(Emp *root)
{
	if(root==NULL)
	return;
	else
	{
	display(root->LC);
	cout<<"\n"<<root->id<<"\t";
	display(root->RC);
	}
}
*/

void Emp :: display(Emp *root)
{	
	int top= -1;
	Emp *temp;
	temp= new Emp;
	temp = root;
	if(root!= NULL)
	{

	do
	{
		while(temp != NULL)
		{
		top++;
		st[top]=temp;
		temp=temp->LC;
		}
		
		if(top!=-1)
		{
		temp=st[top];
		top--;
		cout<<"\n"<<temp->id<<"\t"<<temp->name<<"\t"<<temp->salary<<"\t"<< temp->address;
		temp=temp->RC;
		}
		}
		while(temp!=NULL || top != -1);
		
	} while(temp!=NULL);
	
	
}

/*void Leaf_nodes(Emp *root) 
		{
 		 	  if (root == NULL) return;
    
 		 	  if (root->LC== NULL && root->RC == NULL) 
			{
        				cout << root->chr << " ";
     				   leaf++; 
     			  	 return;
 		   	}
    
  			  printLeaf_nodes(root->LC);
			  printLeaf_nodes(root->RC);
		} 
*/

int main()
{
Emp e;
int choice, i ;
do
{
	cout<<"\n"<<"1.create " << "\n"<<"2.display";
	cout<<"\nEnter your choice";
	cin>> choice;
	switch(choice)
	{
	case 1:  e.create();
		break;
	case 2:  cout<<"\n"<<"ID"<<"\t"<<"Name"<<"\t"<<"Salary" <<"\t"<< "Address" ;
	               e.display( root);
		break;
	}
	cout<<"\nDo you want to continue";
	cin>>i;
} while(i==1);
return 0;
}







































/*	{	
	cout<<"Leaf nodes are :";
	if(temp->RC == NULL && temp-> RC == NULL)
	{
	cout<<"\n" << temp->id<<"\t"<< temp->name<<"\t"<<temp->salary;
	}
	}*/
	




















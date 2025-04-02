// Adjacency list
#include<iostream>
using namespace std;
int i,j;
class GR
{
	int  V ,e;
	int fuel ;
	string city ;
	GR *next;
public : 
	void create();
	void edge();
	void display();
} *head[10];

void GR::display()
{
GR *temp;
for(i=0;i<V;i++)
{
temp=head[i];
while(temp!=NULL)
{
cout<<"->"<<temp->city<<"\t"<<temp->fuel;
temp=temp->next;
}
cout<<"->NULL";
}
}
void GR :: create()
{
	cout<<"Enter no. of cities:";
	cin>> V;
	cout<<"Enter name of cities:";
	for(i=0;i<V;i++)
	{	
		head[i] = new GR;
		cin>> head[i] -> city;
		head[i] -> next = NULL;
	}
}

void GR :: edge()
{	
	string s, d;
	GR  *n1 , *temp;
	
	cout<<"Enter no. of edges:";
	cin>> e;
	for(i=0;i<e;i++)
	{
		cout<<" Enter name of source and destination:";
		cin>> s >> d ;
		for( j=0 ; j< V; j++)
		{
			if(head[j]->city == s)
			{
				break;
			}
		}
		
		n1 = new GR;
		n1-> city = d;
		
		cout << "Enter the fuel needed  ";
		cin>> n1-> fuel;
		
		n1-> next = NULL;
		temp = head[j];
		while(temp->next!= NULL)
		{
			temp = temp-> next;
		}
		temp-> next = n1;
	}
}


int main()
{
	GR g;
	g.create();
	g.edge();
	g.display();
return 0;
}

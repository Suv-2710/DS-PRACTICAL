//  Adjacency Matrix
#include<iostream>
using namespace std;

class GR
{	int i, j , V;
	int adj [100] [100];
	string city[10];
	int fuel;
public :
	void accept();
	void display();
};

void GR :: accept()
{
	cout<<"Enter number of cities:";
	cin>>V;
	cout<<"Enter the names of cities:";
	for(i=0;i<V;i++)
	{
	cin>>city[i];
	}
	for(i=0;i<V;i++)
	{
		for(j=0;j<V;j++) 
		{
		if(i==j)
		{
		adj[i][j]=0;
		}
		else
		{
		cout<<"Enter fuel needed for" << "\t" << city [i]  << " to " <<  city [j];
		cin>>adj[i][j];
		}
		}
	}
}

void GR :: display()
{
	for(i=0;i<V;i++)
	{
		cout<<"\t"<<city[i];
	}
	for(i=0;i<V;i++)
	{
		cout<<"\n"<<city[i];
		for(j=0;j<V;j++)
		{
		cout<<"\t"<<adj[i][j];
		}
	}
}

int main()
{
	GR g;
	g.accept();
	g.display();
return 0;
}


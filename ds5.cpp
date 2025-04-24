// Assignment No. 5 
#include<iostream>
using namespace std;

class WP
{
    int V,i,j;
    string city[10];
    int adj[10][10];
    public : 
        void create();
        void SSP();   
};

void WP :: create()
{
    cout<<"Enter the number of cities you want to add";
    cin >> V;
    cout << "Enter the name of cities :";
    for(i=0; i<V ; i++)
    {
        cin>>city[i];
    }

    for(i=0; i<V ; i++)
    {
        for(j=0; j<V; j++)
        {
            if(i==j)
            {
                adj[i][j]=0;
            }
            else
            {
                cin>> adj[i][j];
            }
        }
    }
}

void WP :: SSP()
{
    int dist[10], visited[10];
    dist[0]= 0;
    for(i=1; i<V ; i++)
    {
        visited[i]= -1;
        dist[i]= 999;
    }
    for(i=0; i<V ; i++) 
    {
        for(j=0; j<V; j++)
        {
            if(adj[i][j] && visited[j] && (dist[i] + adj[i][j]< dist[j]))
            {
                dist[j] = dist[i] + adj[i][j];
            }
        } visited[i]=1;
    }

    for(i=1; i < V ; i++)
    {
        cout << "Distance from " << city[0] <<"to" << city[i] << "is" << dist[i];
    }
}

int main()
{
    WP w;
    w.create();
    w.SSP();
}
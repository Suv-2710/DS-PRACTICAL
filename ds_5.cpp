#include <iostream>
using namespace std;

class WP
{
    int V, i, j;
    string city[10];
    int adj[10][10];
public:
    void create();
    void SSP();
};

void WP::create()
{
    cout << "Enter the number of cities you want to add: ";
    cin >> V;

    cout << "Enter the name of cities: ";
    for (i = 0; i < V; i++)
    {
        cin >> city[i];
    }

    cout << "Enter the adjacency matrix (Enter 0 for no direct path):" << endl;
    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            if (i == j)
            {
                adj[i][j] = 0; // Self loop is zero
            }
            else
            {
                cout << "Distance from " << city[i] << " to " << city[j] << ": ";
                cin >> adj[i][j];
            }

        }
    }
}

void WP::SSP()
{
    int dist[10], visited[10];
    for (i = 0; i < V; i++)
    {
        dist[i] = 999; // Initialize all distances to "infinity"
        visited[i] = 0; // Mark all nodes as unvisited
    }

    dist[0] = 0; // Distance from the source to itself is 0

    for (i = 0; i < V - 1; i++) // Iterate V-1 times
    {
        int minDist = 999, u = -1;

        for (j = 0; j < V; j++) // Find the unvisited node with the smallest distance
        {
            if (!visited[j] && dist[j] < minDist)
            {
                minDist = dist[j];
                u = j;
            }
        }

        if (u == -1) break; // No reachable unvisited nodes left
        visited[u] = 1;

        for (j = 0; j < V; j++) // Update distances of adjacent nodes
        {
            if (!visited[j] && adj[u][j] && dist[u] + adj[u][j] < dist[j])
            {
                dist[j] = dist[u] + adj[u][j];
            }
        }
    }

    cout << "Shortest distances from " << city[0] << ":" << endl;
    for (i = 1; i < V; i++)
    {
        if (dist[i] == 999)
        {
            cout << "No path to " << city[i] << endl;
        }
        else
        {
            cout << "Distance to " << city[i] << " is " << dist[i] << endl;
        }
    }
}

int main()
{
    WP w;
    int choice;

    do
    {
        cout << "\n--- Menu ---" << endl;
        cout << "1. Create Graph" << endl;
        cout << "2. Find Shortest Path (from first city)" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            w.create();
            break;
        case 2:
            w.SSP();
            break;
        case 3:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}

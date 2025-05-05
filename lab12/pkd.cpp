//Implement Prim's, Kruskal's and dijikstra's algorithm of graph adt
#include <iostream>
using namespace std;

#define MAX 10

class Graph
{
    int adj[MAX][MAX];
    int n;

public:
    void create();
    void display();
    void prim();
    void kruskal();
    void dijkstra();
};

void Graph::create()
{
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter adjacency matrix (0 if no edge):\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> adj[i][j];
        }
    }
}

void Graph::display()
{
    cout << "Adjacency Matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}

void Graph::prim()
{
    int selected[MAX] = {0};
    int edges = 0;
    selected[0] = 1;
    int totalCost = 0;
    cout << "\nEdges in MST (Prim):\n";
    while (edges < n - 1)
    {
        int min = MAX, a = -1, b = -1;
        for (int i = 0; i < n; i++)
        {
            if (selected[i])
            {
                for (int j = 0; j < n; j++)
                {
                    if (!selected[j] && adj[i][j] && adj[i][j] < min)
                    {
                        min = adj[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }
        if (a != -1 && b != -1)
        {
            cout << a << " - " << b << " : " << adj[a][b] << endl;
            selected[b] = 1;
            totalCost += adj[a][b];
            edges++;
        }
    }
    cout << "Total cost: " << totalCost << endl;
}

void Graph::kruskal()
{
    int parent[MAX];
    for (int i = 0; i < n; i++)
        parent[i] = i;

    int totalCost = 0;
    int edges = 0;
    cout << "\nEdges in MST (Kruskal):\n";
    while (edges < n - 1)
    {
        int min = MAX, u = -1, v = -1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (adj[i][j] && adj[i][j] < min && parent[i] != parent[j])
                {
                    min = adj[i][j];
                    u = i;
                    v = j;
                }
            }
        }
        if (u != -1 && v != -1)
        {
            cout << u << " - " << v << " : " << adj[u][v] << endl;
            totalCost += adj[u][v];
            int oldParent = parent[v];
            for (int i = 0; i < n; i++)
            {
                if (parent[i] == oldParent)
                    parent[i] = parent[u];
            }
            adj[u][v] = adj[v][u] = 0;
            edges++;
        }
    }
    cout << "Total cost: " << totalCost << endl;
}

void Graph::dijkstra()
{
    int src;
    cout << "Enter source vertex (0 to " << n - 1 << "): ";
    cin >> src;
    int dist[MAX], visited[MAX] = {0};
    for (int i = 0; i < n; i++)
        dist[i] = MAX;
    dist[src] = 0;

    for (int count = 0; count < n - 1; count++)
    {
        int min = MAX, u;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && dist[i] <= min)
            {
                min = dist[i];
                u = i;
            }
        }
        visited[u] = 1;

        for (int v = 0; v < n; v++)
        {
            if (!visited[v] && adj[u][v] && dist[u] != MAX && dist[u] + adj[u][v] < dist[v])
            {
                dist[v] = dist[u] + adj[u][v];
            }
        }
    }

    cout << "\nShortest distances from vertex " << src << ":\n";
    for (int i = 0; i < n; i++)
    {
        cout << "To " << i << " = " << dist[i] << endl;
    }
}

int main()
{
    Graph g;
    int choice;
    do
    {
        cout << "\nMenu:\n1. Create Graph\n2. Display\n3. Prim's MST\n4. Kruskal's MST\n5. Dijkstra's\n6. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            g.create();
            break;
        case 2:
            g.display();
            break;
        case 3:
            g.prim();
            break;
        case 4:
            g.kruskal();
            break;
        case 5:
            g.dijkstra();
            break;
        case 6:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 6);

    return 0;
}

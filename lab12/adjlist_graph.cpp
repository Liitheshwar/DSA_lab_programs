#include <iostream>
#include <vector>

using namespace std;

class Graph 
{
    private:
        int vertices;
        vector<vector<int>> adjList;

    public:
        Graph(int v)
        {
            vertices = v;
            adjList.resize(v);
        }

        void insert(int v, int w);
        void remove(int v, int w);
        bool search(int v, int w);
        void display();
};


int main() {
    Graph g(5);
    
    int ch = 0, loop = 1;
    int v = 0, w = 0;

    while (loop)
    {
        cout << "########## GRAPH ADT ##########\n" << endl;
        cout << "1. Insert Edge\n"
             << "2. Delete Edge\n"
             << "3. search\n"
             << "4. Display\n"
             << "5. Exit\n" << endl;

        cout << "Enter your choice: ";
        cin >> ch;

        switch(ch)
        {
            case 1:
                cout << "Enter the vertices: ";
                cin >> v >> w;
                g.insert(v, w);

                break;
            case 2:
                cout << "Enter the vertices: ";
                cin >> v >> w;
                g.remove(v, w);

                break;
            case 3:
                cout << "Enter the vertices: ";
                cin >> v >> w;
                g.search(v, w);

                break;
            case 4:
                g.display();

                break;
            case 5:
                loop = 0;

                break;
            default:
                cout << "Invalid choice\n" << endl;

                break;
        }

        cout << "###############################\n" << endl;
    }

    return 0;
}

void Graph::insert(int v, int w)
{
    if ( v >= 0 && v < vertices && w >= 0 && w < vertices) {
        for (int u : adjList[v])
        {
            if (u == w) {
                cout << "Edge already exists" << endl;
                return;
            }
        }

        adjList[v].push_back(w);
        adjList[w].push_back(v);
    }
    else {
        cout << "Invalid vertex" << endl;
    }
}

void Graph::remove(int v, int w)
{
    int check = 0;
    if ( v >= 0 && v < vertices && w >= 0 && w < vertices) {
        for (int i = 0; i < adjList[v].size(); i++)
        {
            if (adjList[v][i] == w) {
                adjList[v].erase(adjList[v].begin() + i);
                check = 1; 
                break;
            }
        }

        if (check == 1) {
            for (int i = 0; i < adjList[w].size(); i++)
            {
                if (adjList[w][i] == v) {
                    adjList[w].erase(adjList[w].begin() + i);
                    return;
                }
            }
        }
        else {
            cout << "Edge does not exist" << endl;
        }
        return;
    }
    else {
        cout << "Invalid vertex" << endl;
    }
}

bool Graph::search(int v, int w)
{
    if ( v >= 0 && v < vertices && w >= 0 && w < vertices) {
        for (int u : adjList[v]) 
        {
            if (u == w) {
                cout << "Edge exists" << endl;
                return true;
            }
        }
        cout << "Edge does not exist" << endl;
        return false;
    }
    else {
        cout << "Invalid vertex" << endl;
        return false;
    }
}

void Graph::display()
{
    cout << "Adjacency List:" << endl;
    for (int i = 0; i < vertices; i++)
    {
        cout << i << " -> ";
        for (int u : adjList[i])
        {
            cout << u << " ";
        }
        cout << endl;
    }
}

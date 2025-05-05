#include <iostream>
#include <vector>

using namespace std;

class Graph
{
    private:
        vector< vector<int> > adjmatrix;
        int vertices;

    public:
        Graph(int v)
        {
            vertices = v;
            adjmatrix.resize(v, vector<int>(v, 0));
        }

        void insert(int v, int w);
        void remove(int v, int w);
        void search(int v, int w);
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
    if (v >= 0 && v < vertices && w >= 0 && w < vertices) {
        if (adjmatrix[v][w] == 0) {
            adjmatrix[v][w] = 1;
            adjmatrix[w][v] = 1;    
        }
        else {
            cout << "Edge already exists" << endl;
            return;
        }
    }
    else {
        cout << "Invalid vertex" << endl;
    }
}

void Graph::remove(int v, int w)
{
    if (v >= 0 && v < vertices && w >= 0 && w < vertices) {
        if (adjmatrix[v][w] == 1) {
            adjmatrix[v][w] = 0;
            adjmatrix[w][v] = 0;
        }
        else {
            cout << "Edge does not exist" << endl;
            return;
        }
    }
    else {
            cout << "Invalid vertex" << endl;
    }
}

void Graph::search(int v, int w)
{
    if (v >= 0 && v < vertices && w >= 0 && w < vertices) {
        if (adjmatrix[v][w] == 1) {
            cout << "Edge exists" << endl;
        }
        else {
            cout << "Edge does not exist" << endl;
        }
    }
    else {
        cout << "Invalid vertex" << endl;
    }
}

void Graph::display()
{
    cout << "Adjacency Matrix:" << endl;
    cout << "   0 1 2 3 4" << endl;
    cout << "  -----------" << endl;

    for (int i = 0; i < vertices; i++) {
        cout << i << ": ";

        for (int j = 0; j < vertices; j++) {
            cout << adjmatrix[i][j] << " ";
        }
        cout << endl;
    }
}
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <string>
// #include <stack>

using namespace std;

class Graph
{
private:
    list<int> *l;
    int V;

public:
    Graph(int V)
    {
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    bool cycleHelper(int node, bool *visited, int parent)
    {

        // then  we  visit the node
        visited[node] = true;

        for (int nbr : l[node])
        {
            // two cases
            if (stack[nbr] == true)
            {
                return true;
            }
            else if (visited[nbr] == false)
            {
                bool cycle_mila = cycleHelper(nbr, visited, stack);

                if (cycle_mila)
                {
                    return true;
                }
            }
        }
        // when we are returing from the  node

        stack[node] = false;
        return false;
    }

    bool isCycle()
    {
        bool *visited = new bool[V];
        int *parent = new int[V];

        for (int i = 0; i < V; i++)
        {
            visited[i] = false;
        }

        return cycleHelper(0, visited);
    }
};

int main()
{
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 0);
    // g.addEdge(1, 5);
    // g.addEdge(5, 6);
    // g.addEdge(4, 2);

    cout << g.isCycle();
}
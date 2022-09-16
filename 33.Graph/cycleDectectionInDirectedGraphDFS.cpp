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
    }

    bool cycleHelper(int node, bool *visited, bool *stack)
    {

        // then  we  visit the node
        visited[node] = true;
        stack[node] = true;

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
        bool *stack = new bool[V];

        for (int i = 0; i < V; i++)
        {
            visited[i] = stack[i] = false;
        }

        return cycleHelper(0, visited, stack);
    }
};

int main()
{
    Graph g(1);
    g.addEdge(0, 0);
    // g.addEdge(1, 2);
    // g.addEdge(2, 3);
    // g.addEdge(3, 4);
    // g.addEdge(4, 5);
    // g.addEdge(1, 5);
    // g.addEdge(5, 6);
    // g.addEdge(4, 2);

    cout << g.isCycle();
}
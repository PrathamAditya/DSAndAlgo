/**
 * author: adityapratham
 **/
#include <iostream>
#include <list>
#include <map>
#include <queue>
using namespace std;

template <typename T>

class Graph
{
    map<T, list<T>> l;

public:
    void addEdge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void DFSHelper(T src, map<T, bool> &visited)
    {
        cout << src << " ";
        visited[src] = true;

        // go to any nbr of that node that is not visited;
        for (T nbr : l[src])
        {
            if (!visited[nbr])
            {
                DFSHelper(nbr, visited);
            }
        }
    }
    void DFS()
    {
        map<T, bool> visited;

        // make all the nodes as not visited in the begining
        for (auto p : l)
        {
            T node = p.first;
            visited[node] = false;
        }
        // iterate over the vertices and init a dfs
        int cnt = 0;
        for (auto x : l)
        {
            T node = x.first;

            if (!visited[node])
            {
                cout << "Component: " << cnt << "-->";
                DFSHelper(node, visited);
                cnt++;
                cout << "\n";
            }
        }
    }
};

using namespace std;

int main()
{
    Graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(0, 3);
    g.addEdge(0, 4);

    g.addEdge(5, 6);
    g.addEdge(6, 7);

    g.addEdge(8, 8);

    g.DFS();

    return 0;
}
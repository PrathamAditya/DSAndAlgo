/**
 * author: adityapratham
 **/
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <string>
using namespace std;

// todo -
//

template <typename T>
class Graph
{
    map<T, list<T>> l;

public:
    void addEdge(T x, T y)
    {
        l[x].push_back(y);
    }

    void DFSHelper(T src, map<T, bool> &visited, list<T> &ordering)
    {
        visited[src] = true;

        // go to any nbr of that node that is not visited;
        for (T nbr : l[src])
        {
            if (!visited[nbr])
            {
                DFSHelper(nbr, visited, ordering);
            }
        }
        ordering.push_front(src);
        return;
    }
    void DFS()
    {
        map<T, bool> visited;
        list<T> ordering;

        // make all the nodes as not visited in the begining
        for (auto p : l)
        {
            T node = p.first;
            visited[node] = false;
        }
        // iterate over the vertices and init a dfs
        for (auto x : l)
        {
            T node = x.first;

            if (!visited[node])
            {
                DFSHelper(node, visited, ordering);
            }
        }

        // finally

        for (auto x : ordering)
        {
            cout << x << "\n";
        }
    }
};

using namespace std;

int main()
{
    Graph<string> g;
    g.addEdge("Python", "Data Preprocessing");
    g.addEdge("Python", "ML Basics");
    g.addEdge("Python", "Py torch");
    g.addEdge("Py torch", "Data Learning(DL)");
    g.addEdge("ML Basics", "Deep Learning");
    g.addEdge("Deep Learning", "Face reco");
    g.addEdge("Data set", "Face reco");
    g.DFS();

    return 0;
}
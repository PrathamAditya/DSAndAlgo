/**
 * author: adityapratham
 **/
#include <bits/stdc++.h>
#include <unordered_map>
#include <queue>
#include <list>
#include <map>

using namespace std;

template <typename T>
class Graph
{
private:
    map<T, list<T>> l;

public:
    void addEdge(T a, T b)
    {
        l[a].push_back(b);
        l[b].push_back(a);
    }

    void print()
    {
        for (auto p : l)
        {
            auto city = p.first;
            auto nbrs = p.second;
            cout << city << "->";
            for (auto nbr : nbrs)
            {
                cout << nbr << ",";
            }
            cout << "\n";
        }
    }

    void SSSP(T src)
    {
        map<T, int> dist;
        queue<T> q;
        q.push(src);
        dist[src] = 0;

        for (auto x : l)
        {
            dist[x.first] = INT_MAX;
        }
        dist[src] = 0;

        while (!q.empty())
        {
            T node = q.front();
            q.pop();
            for (auto nbr : l[node])
            {
                if (dist[nbr] == INT_MAX)
                {
                    dist[nbr] = dist[node] + 1;
                    q.push(nbr);
                }
            }
        }

        // printing the distance

        for (auto x : dist)
        {
            cout << x.first << "->" << x.second << "\n";
        }
    }
};

int main()
{

    Graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 6);

    g.SSSP(0);

    // Graph<string> g;
    // g.addEdge("A", "B", 20);
    // g.addEdge("B", "D", true, 40);
    // g.addEdge("A", "C", true, 10);
    // g.addEdge("C", "B", true, 40);
    // g.addEdge("A", "D", false, 20);

    // g.BFS("A");
    return 0;
}
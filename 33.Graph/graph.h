/**
 * author: adityapratham
 **/
#include <bits/stdc++.h>
#include <map>

using namespace std;
template <typename T>
class Graph
{

public:
    void addEdge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void BFS(T src)
    {
        map<T, bool> visited;
        queue<T> q;
        q.push(src);
        visited[src] = true;

        while (!q.empty())
        {
            T node = q.front();
            q.pop();
            cout << node << " ";

            for (auto nbr : l[node])
            {
                if (!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
    }
    void shortestPath(T src)
    {
        map<T, int> dist;
        queue<T> q;

        // iterate over the graph
        for (auto x : l)
        {
            auto node = x.first;
            dist[node] = INT_MAX;
        }
        q.push(src);
        dist[src] = 0;

        while (!q.empty())
        {
            T node = q.front();
            q.pop();
            // cout << node << " ";

            for (auto nbr : l[node])
            {
                if (dist[nbr] == INT_MAX)
                {
                    q.push(nbr);
                    dist[nbr] = dist[node] + 1;
                }
            }
        }

        // Print the dist to every node
        for (auto x : l)
        {
            T node = x.first;
            int d = dist[node];

            cout << "Node: " << node << "-" << d << "\n";
        }
    }
};

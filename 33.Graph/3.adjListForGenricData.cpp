/**
 * author: adityapratham
 **/
#include <bits/stdc++.h>
#include <unordered_map>
#include <list>

using namespace std;

class Graph
{
private:
    unordered_map<string, list<pair<string, int>>> l;

public:
    void addEdge(string a, string b, bool isBiDir, int wt)
    {
        l[a].push_back(make_pair(b, wt));
        if (isBiDir)
        {
            l[b].push_back(make_pair(a, wt));
        }
    }

    void print()
    {
        for (auto p : l)
        {
            string city = p.first;
            list<pair<string, int>> nbrs = p.second;
            cout << city << "->";
            for (auto nbr : nbrs)
            {
                string dest = nbr.first;
                int dist = nbr.second;

                cout << "(" << dest << "-" << dist << ")"
                     << ",";
            }
            cout << "\n";
        }
    }
    void bfs(T src)
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
};

int main()
{
    Graph g;
    g.addEdge("A", "B", true, 20);
    g.addEdge("B", "D", true, 40);
    g.addEdge("A", "C", true, 10);
    g.addEdge("C", "B", true, 40);
    g.addEdge("A", "D", false, 20);

    g.bfs();
    return 0;
}
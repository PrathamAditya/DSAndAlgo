/**
 * author: adityapratham
 **/
#include <bits/stdc++.h>
#include <map>
using namespace std;

template <typename T>
class Graph
{
    map<T, list<T>> l;

public:
    void addEdge(int x, int y)
    {
        l[x].push_back(y);

        // using directed Edges
        // l[y].push_back(x);
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
    void shortestPath(T src, T dest)
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

int main()
{
    int board[50] = {0};

    // snakes and ladders
    board[2] = 13;
    board[5] = 2;
    board[9] = 18;
    board[18] = 11;
    board[17] = -13;
    board[20] = -14;
    board[24] = -8;
    board[25] = 10;
    board[32] = -2;
    board[34] = -22;

    // Add all the edges to the graph

    Graph<int> g;

    for (int i = 0; i <= 36; i++)
    {
        for (int dice = 1; dice <= 6; dice++)
        {
            int j = i + dice;
            j += board[j];

            if (j <= 36)
            {
                g.addEdge(i, j);
            }
        }
    }
    g.addEdge(36, 36);

    g.shortestPath(0, 36);

    return 0;
}
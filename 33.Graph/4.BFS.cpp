/**
 * author: adityapratham
 **/
#include <bits/stdc++.h>
#include <unordered_map>
#include <queue>
#include <list>
#include <map>

using namespace std;

// class Graph
// {
// private:
//     map<int, list<int>> m;

// public:
//     void addEdge(int a, int b)
//     {
//         m[a].push_back(b);
//         m[b].push_back(a);
//     }

//     void print()
//     {
//         for (auto x : m)
//         {
//             cout << x.first << "->";
//             for (auto node : x.second)
//             {
//                 cout << node << ",";
//             }
//             cout << "\n";
//         }
//     }

//     void BFS(int src)
//     {
//         queue<int> q;
//         map<int, bool> visited;

//         q.push(src);
//         visited[src] = true;

//         while (!q.empty())
//         {
//             int node = q.front();
//             q.pop();

//             cout << node << " ";
//             for (auto x : m[node])
//             {
//                 if (!visited[x])
//                 {
//                     visited[x] = true;
//                     q.push(x);
//                 }
//             }
//         }
//     }
// };

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
    // void bfs(T src)
    // {
    //     map<T, bool> visited;
    //     queue<T> q;
    //     q.push(src);
    //     visited[src] = true;

    //     while (!q.empty())
    //     {
    //         T node = q.front();
    //         q.pop();
    //         cout << node << " ";

    //         for (auto nbr : l[node])
    //         {
    //             if (!visited[nbr])
    //             {
    //                 q.push(nbr);
    //                 visited[nbr] = true;
    //             }
    //         }
    //     }
    // }

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
            cout << node << "-";

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

    Graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(3, 0);
    g.addEdge(4, 5);
    g.print();

    // Graph<string> g;
    // g.addEdge("A", "B", 20);
    // g.addEdge("B", "D", true, 40);
    // g.addEdge("A", "C", true, 10);
    // g.addEdge("C", "B", true, 40);
    // g.addEdge("A", "D", false, 20);

    // g.BFS("A");
    return 0;
}
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <string>
#include <unordered_map>
#include <set>

using namespace std;

template <typename T>
class Graph
{
private:
    unordered_map<T, list<pair<T, int>>> m;

public:
    void addEdge(T U, T V, int dist, bool bidir = true)
    {
        m[U].push_back(make_pair(V, dist));
        if (bidir)
        {
            m[V].push_back(make_pair(U, dist));
        }
    }

    void printAdj()
    {
        // first all the key values pair in the map
        for (auto x : m)
        {
            cout << x.first << "->";
            for (auto nbr : x.second)
            {
                T node = nbr.first;
                int dist = nbr.second;
                cout << " (" << node << "," << dist << ") ";
            }
            cout << "\n";
        }
    }

    void dijSSSP(T src)
    {
        unordered_map<T, int> dist;

        // set all distances to infinity
        for (auto j : m)
        {
            dist[j.first] = INT_MAX;
        }

        // Make  a set to find out node with the minimum distance
        set<pair<int, T>> s;
        dist[src] = 0;
        s.insert(make_pair(0, src));

        while (!s.empty())
        {
            // find the pair at front
            auto p = *(s.begin());

            T node = p.second;
            int nodeDist = p.first;
            s.erase(s.begin());

            // terrate over the nbr or child of current node
            for (auto childPair : m[node])
            {
                T dest = childPair.first;

                if (nodeDist + childPair.second < dist[childPair.first])
                {
                    // in the set/PQ updation of paricular node not possible
                    // we have to remove the old pair  ,  and insert the new pair to simulate the updation

                    auto f = s.find(make_pair(dist[dest], dest));
                    if (f != s.end())
                    {
                        s.erase(f);
                    }
                }
                // insert the new pair
                dist[dest] = nodeDist + childPair.second;
                s.insert(make_pair(dist[dest], dest));
            }
        }

        // print distances to all other nodes
        for (auto d : dist)
        {
            cout << d.first << " distance is: " << d.second << "\n";
        }
    }
};

int main()
{

    Graph<int> g;
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 4);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 2);
    g.addEdge(1, 4, 7);
    g.dijSSSP(1);

    // Graph<string> g;
    // g.addEdge("Amritsar", "Delhi", 1);
    // g.addEdge("Amritsar", "Jaipur", 4);
    // g.addEdge("Jaipur", "Delhi", 2);
    // g.addEdge("Jaipur", "Mumbai", 8);
    // g.addEdge("Mumbai", "Bhopal", 3);
    // g.addEdge("Bhopal", "Agra", 2);
    // g.addEdge("Delhi", "Agra", 1);
    // g.printAdj();
}
#include <bits/stdc++.h>
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
    void bfs(T src)
    {
        map<T, int> distance;
        queue<T> q;

        // making distance as INT_MAX for all nodes
        for (auto node_pair : l)
        {
            T node = node_pair.first;
            distance[node] = INT_MAX;
        }
        q.push(src);
        distance[src] = 0;

        while (!q.empty())
        {
            T node = q.front();
            q.pop();
            for (int nbr : l[node])
            {
                if (distance[nbr] == INT_MAX)
                {
                    q.push(nbr);
                    //mark nbr as visited
                    distance[nbr] = distance[node] + 1;
                }
            }
        }
        // Print distance to every node from source node
        for (auto node_pair : l)
        {
            T node = node_pair.first;
            int d = distance[node]; 
            cout << "Node " << node << " is at distance " << d << " from source node" << endl;
        }

        // for(auto d:distance){
        //     cout<<"Node "<<d.first<<" is at distance "<< d.second<<" from source node"<<endl;
        // }
    }
};

int main()
{
    Graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.bfs(0);
    return 0;
}

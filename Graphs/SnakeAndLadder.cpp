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
    }
    int bfs(T src, T dest)
    {
        map<T, int> distance;
        map<T, T> parent;
        queue<T> q;

        // making distance as INT_MAX for all nodes
        for (auto node_pair : l)
        {
            T node = node_pair.first;
            distance[node] = INT_MAX;
        }
        q.push(src);
        distance[src] = 0;
        parent[src] = src;

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
                    parent[nbr] = node;
                }
            }
        }

        // Print the distance to dest node
        // Dest to src
        T temp = dest;
        while (temp != src)
        {
            cout << temp << "<--";
            temp = parent[temp];
        }
        cout << src << endl;
        // Returning distance to destination
        return distance[dest];
    }
};

int main()
{
    Graph<int> g;

    int boards[50] = {0};
    boards[2] = 13;
    boards[5] = 2;
    boards[9] = 18;
    boards[18] = 11;
    boards[17] = -13;
    boards[20] = -14;
    boards[24] = -8;
    boards[25] = 10;
    boards[32] = -2;
    boards[34] = -22;

    for (int i = 0; i < 37; i++)
    {
        for (int dice = 1; dice <= 6; dice++)
        {
            int j = i + dice;
            j += boards[j];
            if (j <= 36)
            {
                g.addEdge(i, j);
            }
        }
    }
    g.addEdge(36,36);
    cout << "Shortest distance is " << g.bfs(0, 36) << endl;
    return 0;
}



// #include <bits/stdc++.h>
// using namespace std;

// template <typename T>
// class Graph
// {
//     map<T, list<T>> l;

// public:
//     void addEdge(int x, int y)
//     {
//         l[x].push_back(y);
//         l[y].push_back(x);
//     }
//     void bfs(T src)
//     {
//         map<T, int> visited;
//         queue<T> q;

//         q.push(src);
//         visited[src] = true;

//         // Algo time o(pow(n,2));
//         while (!q.empty())
//         {
//             T node = q.front();
//             q.pop();
//             cout << node << "->";
//             for (auto nbr : l[node])
//             {
//                 if (!visited[nbr])
//                 {
//                     q.push(nbr);
//                     //mark nbr as visited
//                     visited[nbr] = true;
//                 }
//             }
//         }
//     }
// };

// int main()
// {
//     Graph<int> g;
//     g.addEdge(1, 2);
//     g.addEdge(0, 1);
//     g.addEdge(2, 3);
//     g.addEdge(3, 4);
//     g.addEdge(4, 5);
//     g.bfs(0);
//     return 0;
// }




#include <bits/stdc++.h>
using namespace std;

class Graph
{
    map<int, list<int>> l;

public:
    void addEdge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void bfs(int src)
    {
        map<int, int> visited;
        queue<int> q;

        q.push(src);
        visited[src] = true;

        // Algo time O(pow(n,2));
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            cout << node << "->";
            for (auto nbr : l[node])
            {
                if (!visited[nbr])
                {
                    q.push(nbr);
                    //mark nbr as visited
                    visited[nbr] = true;
                }
            }
        }
    }
};

int main()
{
    Graph g;
    g.addEdge(1, 2);
    g.addEdge(0, 1);
    g.addEdge(2, 3);
    g.addEdge(0,3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.bfs(0);
    return 0;
}
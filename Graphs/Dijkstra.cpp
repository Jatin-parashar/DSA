#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Graph
{
    map<T, list<pair<T, int>>> l;

public:
    void addEdge(T x, T y, int wt, bool bi = true)
    {
        l[x].push_back(make_pair(y, wt));
        if (bi)
        {
            l[y].push_back(make_pair(x, wt));
        }
    }


    void adjacencyList(){
        for(auto node_pair:l){
            cout<<node_pair.first<<" -->";
            for(auto node:node_pair.second){
                cout<<" ("<<node.first<<","<<node.second<<")";
            }
            cout<<endl;
        }
    }
    void dj(T src)
    {
        map<T, int> distance;
        // making distance as INT_MAX for all nodes
        for (auto node_pair : l)
        {
            T node = node_pair.first;
            distance[node] = INT_MAX;
        }

        set<pair<int,T>> s;

        s.insert({0,src});
        distance[src] = 0;

        while (!s.empty())
        {
            auto p = s.begin();
            T node = p->second;
            int nodeDist = p->first;
            s.erase(s.begin());


            for (auto nbr : l[node])
            {
                if (nodeDist + nbr.second<distance[nbr.first])
                {
                    // we can't update in set 
                    // we will remove old pair and insert a new one
                    T dest = nbr.first;
                    auto f = s.find(make_pair(distance[dest],dest));
                    if(f!=s.end()){
                        s.erase(f);
                    }

                    //insert the new_pair
                    distance[dest]=nodeDist + nbr.second;
                    s.insert(make_pair(distance[dest],dest));
                }
            }
        }
        // Print distance to every node from source node
        // for (auto node_pair : l)
        // {
        //     T node = node_pair.first;
        //     int d = distance[node];
        //     cout << node << " is at distance " << d << " from source" << endl;
        // }

        for(auto d:distance){
            cout<<"Node "<<d.first<<" is at distance "<< d.second<<" from source node"<<endl;
        }
    }
};

int main()
{
    Graph<string> g;
    // 7 edges and 6 nodes in my example
    g.addEdge("Amritsar","Delhi",1);
    g.addEdge("Amritsar","Jaipur",4);
    g.addEdge("Jaipur","Delhi",2);
    g.addEdge("Jaipur","Mumbai",8);
    g.addEdge("Mumbai","Bhopal",3);
    g.addEdge("Bhopal","Agra",2);
    g.addEdge("Delhi","Agra",1);
    g.adjacencyList();

    cout<<endl;
    g.dj("Amritsar");
    return 0;


}

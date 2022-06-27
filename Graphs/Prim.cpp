#include<bits/stdc++.h>
using namespace std;


class Graph{
    // Adjacency List
    int V;
    map<int,list<pair<int,int>>> l;

    public:
        Graph(int V){
            this->V=V;
        }

        void addEdge(int x,int y,int w){
            l[x].push_back({w,y});
            l[y].push_back({w,x});
        }

        int prims_mst(){
            // by default it makes a max-heap but we need a min-heap. This will store active edges
            priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;


            // visited vector which denotes whether a node has been included in mst or not and initialising with 0
            vector<bool> visited(V,false);

            int minimum_cost=0;

            pq.push({0,0}); //wt,y

            while(!pq.empty()){
                
                //pick the topmost edge as it will be of minimum weight
                auto edge = pq.top();
                pq.pop();

                int w=edge.first;
                int y=edge.second;

                if(!visited[y]){
                    minimum_cost+=w;
                    visited[y]=true;


                    // add the new edges to the pq
                    for(auto x:l[y]){
                        if(!visited[x.second]){
                            pq.push({x.first,x.second});
                        }
                    }
                }
            }
            return minimum_cost;
        }

};
int main(){
    int n,m;
    cin>>n>>m;

    Graph g(n);
    for (int i = 0; i < m; i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        g.addEdge(x,y,w);
    }
    cout<<g.prims_mst();

    return 0;
}

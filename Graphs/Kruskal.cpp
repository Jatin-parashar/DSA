#include <bits/stdc++.h>
using namespace std;

class DSU{
    int *parent;
    int *rank;
    public:
        DSU(int n){
            parent=new int[n];
            rank=new int[n];
            for(int i=0;i<n;i++){
                parent[i]=-1;
                rank[i]=1;
            }
        }

        int find_set(int node){
            if(parent[node]==-1){
                return node;
            }
            //path compression
            return parent[node]=find_set(parent[node]);
        }

        void union_set(int x,int y){
            int s1=find_set(x);
            int s2=find_set(y);

            if(s1!=s2){
                if(rank[s1]<rank[s2]){
                    parent[s1]=s2;
                    rank[s2]+=rank[s1];
                }
                else{
                    parent[s2]=s1;
                    rank[s1]+=rank[s2];
                }
            }
        }
};


class Graph{
    int V;
    vector<vector<int>> edgeList;
    public:
        Graph(int V){
            this->V=V;
        }

        void addEdge(int x,int y,int w){
            edgeList.push_back({w,x,y});
        }

        int kruskal_mst(){
            //step-1 sort the edgeList based on weights
            sort(edgeList.begin(),edgeList.end());

            DSU s(V);

            //step-2 Traverse the list. if an edge forms cycle,discard it. else consider it
            int minimum_cost=0;
            for(auto edge:edgeList){
                int w=edge[0];
                int x=edge[1];
                int y=edge[2];
                
                int s1=s.find_set(x);
                int s2=s.find_set(y);
                if(s1!=s2){
                    s.union_set(x,y);
                    minimum_cost+=w;
                }
            }
            return minimum_cost;
        }
};

int main() {
    int n,m;
    cin>>n>>m;
    Graph g(n);
   for(int i=0;i<m;i++){
       int x,y,w;
       cin>>x>>y>>w;
       g.addEdge(x-1,y-1,w);
   }
    cout<<g.kruskal_mst();
    return 0;
}

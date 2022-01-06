// https://www.hackerrank.com/challenges/journey-to-the-moon/problem

#include <bits/stdc++.h>
using namespace std;
vector<long> sizes;

#define pb push_back
class Graph{
    map<long,list<int>> l;
    public:
        Graph(long n){
            for(int i=0;i<n;i++){
                l[i]={};
            }
        }
        void addEdge(long x,long y){
            l[x].pb(y);
            l[y].pb(x);
        }
        
long cnt=0;
        void dfs_helper(long node,map<long,bool> &visited){
            cnt++;
            visited[node]=true;
            for(long nbr:l[node]){
                if(!visited[nbr]){
                    dfs_helper(nbr,visited);
                }
            }
            
        }
        void dfs(long n){
            map<long,bool> visited;
            for(long i=0;i<n;i++){
                visited[n]=false;
            }
            
            for(auto p:l){
                long node=p.first;
                cnt=0;
                if(!visited[node]){
                    dfs_helper(node,visited);
                    sizes.pb(cnt);
                }
            }    
        }
};

long nC2(long n){
    if(n<2){
        return 0;
    }
    if(n==2){
        return 1;
    }
    return n*(n-1)/2;
}

int main(){
    long n,p;
    cin>>n>>p;
    Graph g(n);
    
    for(long i=0;i<p;i++){
        long x,y;
        cin>>x>>y;
        g.addEdge(x,y);
    }

    g.dfs(n);
    long ans=0;
    for(long i=0;i<sizes.size();i++){
        ans+=nC2(sizes[i]);
    }
    ans=nC2(n)-ans;
    cout<<ans;
    return 0;
}

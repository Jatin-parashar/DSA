// cycle detection in an undirected graph using DSU

#include <bits/stdc++.h>
using namespace std;

//DSU - Find
int find_set(int node, vector<int> &parent)
{
    if (parent[node] == -1)
    {
        return node;
    }
    //path compression optimisation
    return parent[node]=find_set(parent[node], parent);
}

//DSU - Union
void union_set(int x, int y, vector<int> &parent,vector<int> &rank)
{
    int s1 = find_set(x, parent);
    int s2 = find_set(y, parent);


    //union by rank
    if (s1 != s2)
    {
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


bool contains_cycle(int n, list<pair<int, int>> l)
{
    vector<int> parent(n, -1);
    vector<int> rank(n, 1);

    for (auto edge : l)
    {
        int x = edge.first;
        int y = edge.second;
        int s1 = find_set(x, parent);
        int s2 = find_set(y, parent);

        if (s1 != s2)
        {
            union_set(x,y,parent,rank);
        }
        else{
            //if s1 and s2 are equal, this means that x and y belong to same set and so their super parents are same and hence a cycle is present.
            return true;
        }
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    list<pair<int, int>> l;

    while (m--)
    {
        int x, y;
        cin >> x >> y;
        l.push_back(make_pair(x, y));
    }
    if(contains_cycle(n,l)){
        cout<<"Contains cycle"<<endl;
    }
    else{
        cout<<"No cycle"<<endl;
    }
    return 0;
}

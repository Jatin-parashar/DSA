// For an undirected Graph with nodes starting from 0

// #include<iostream>
// #include<list>


#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    // List to store nodes pointing to dynamic lists containing neighbours
    list<int> *l;
    public:
        Graph(int V){
            this->V=V;
            // Initialising list with V elements and making 2D for individual lists
            l=new list<int>[V];
        }
        // Adding add
        void addEdge(int x,int y){
            l[x].push_back(y);
            l[y].push_back(x);
        }
        // Printing the adjacency list
        void AdjacencyList(){
            for (int i = 0; i < V; i++)
            {
                cout<<i<<" -> ";
                for(int nbr:l[i]){
                    cout<<nbr<<" ";
                }
                cout<<endl;
            }
        }
};


int main(){
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.AdjacencyList();
    return 0;
}

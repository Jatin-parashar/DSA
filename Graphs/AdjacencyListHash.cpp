// For a directed Graph with nodes as strings

#include<iostream>
#include<map>
#include<list>
#include<cstring>
using namespace std;

class Graph{
    // Can use unordered map as well
    // map<node_name,list<pair<node_name,weightOfEdge>> l;
    map<string,list<pair<string,int>>> l;
    public:
        void addEdge(string x,string y,bool bi, int wt){
            l[x].push_back(make_pair(y,wt));
            if(bi){
                l[y].push_back(make_pair(x,wt));
            }
        }
        void print(){
            for(auto node:l){
                cout<<node.first<<" -> ";
                list<pair<string,int>> nbr=node.second;
                for(auto n:nbr){
                    cout<<"("<<n.first<<","<<n.second<<") ";
                }
                cout<<endl;
            }
        }
};

int main() {
    Graph g;
    // g.addEdge("A","D",false,50);
    // g.addEdge("A","B",true,20);
    // g.addEdge("A","C",true,10);
    // g.addEdge("B","D",true,30);
    // g.addEdge("C","D",true,40);
    g.addEdge("A","F",false,40);
    g.addEdge("A","C",false,40);
    g.addEdge("A","B",false,40);
    g.addEdge("F","D",false,40);
    g.addEdge("C","F",false,40);
    g.addEdge("B","G",false,40);
    g.addEdge("B","C",false,40);
    g.addEdge("D","C",false,40);
    g.addEdge("E","C",false,40);
    g.addEdge("E","D",false,40);
    g.addEdge("E","J",false,40);
    g.addEdge("G","C",false,40);
    g.addEdge("G","E",false,40);
    g.addEdge("J","D",false,40);
    g.addEdge("J","K",false,40);
    g.addEdge("K","E",false,40);
    g.addEdge("K","G",false,40);

    g.print();
    return 0;
}

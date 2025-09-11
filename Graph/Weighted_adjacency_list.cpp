#include<iostream>
#include<list>
#include<vector>
using namespace std;

int v;
int e;
vector<list<pair<int, int>>> graph;

// undirected graph to make it directed just call 
void add_edge(int src, int des, int wt, bool bi_dir = true) {
    graph[src].push_back({des, wt});
    if(bi_dir) {
        graph[des].push_back({src, wt});
    }
}

int main() {
    cin>>v;
    graph.resize(v, list<pair<int, int>> ());
    cin>>e;
    while(e--) {
        int s, d, wt;
        cin>>s>>d>>wt;
        add_edge(s, d, wt); // also by adding false to make it directed
    }

    for(int i = 0; i < graph.size(); i++) {
        cout<< i << "->";
        for(auto ele: graph[i]) {
            cout<< "(" << ele.first << " " << ele.second << "),";
        }
        cout<<endl;
    }
}
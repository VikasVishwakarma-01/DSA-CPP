#include<iostream>
#include<list>
#include<vector>
using namespace std;

int v;
int e;
vector<list<int>> graph;

// undirected graph to make it directed just call 
void add_edge(int src, int des, bool bi_dir = true) {
    graph[src].push_back(des);
    if(bi_dir) {
        graph[des].push_back(src);
    }
}

int main() {
    cin>>v;
    graph.resize(v, list<int> ());
    cin>>e;
    while(e--) {
        int s, d;
        cin>>s>>d;
        add_edge(s, d); // also by adding false to make it directed
    }

    for(int i = 0; i < graph.size(); i++) {
        cout<< i << "->";
        for(auto ele: graph[i]) {
            cout<< ele << ",";
        }
        cout<<endl;
    }
}
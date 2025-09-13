#include<iostream>
#include<list>
#include<vector>
#include<unordered_set>
using namespace std;

int v, e;
vector<list<int>> graph;

// undirected graph to make it directed just call 
void add_edge(int src, int des, bool bi_dir = true) {
    graph[src].push_back(des);
    if(bi_dir) {
        graph[des].push_back(src);
    }
}

void dfs(int node, unordered_set<int>& visited) {
    visited.insert(node);
    for(auto neighbor: graph[node]) {
        if(visited.count(neighbor) == 0) {
            dfs(neighbor, visited);
        }
    }
}

int connected_components() {
    int result = 0;
    unordered_set<int> visited;
    for(int i = 0; i < v; i++) {
        if(visited.count(i) == 0) {
            result++;
            dfs(i, visited);
        }
    }
    return result;
}

int main() {
    cin>>v>>e;
    graph.resize(v, list<int> ());
    while(e--) {
        int s, d;
        cin>>s>>d;
        add_edge(s, d); // also by adding false to make it directed
    }
    cout<<connected_components()<<endl;
    
}
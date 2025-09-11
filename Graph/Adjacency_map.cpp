#include<iostream>
#include<list>
#include<vector>
#include<unordered_map>
using namespace std;

int v;
int e;
vector<unordered_map<int, int>> graph;

// undirected graph to make it directed just call 
void add_edge(int src, int des, int wt, bool bi_dir = true) {
    graph[src][des]= wt;
    if(bi_dir) {
        graph[des][src]= wt;
    }
}

int main() {
    cin>>v;
    graph.resize(v, unordered_map<int, int> ());
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
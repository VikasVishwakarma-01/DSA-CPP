#include <bits/stdc++.h>
using namespace std;


bool canVisitAllRooms(vector<vector<int>>& rooms) {
    unordered_set<int> visited;

    queue<int> q;
    q.push(0);
    visited.insert(0);
    while(q.size() > 0) {
        int curr = q.front();
        q.pop();
        for(auto x: rooms[curr]) {
            if(visited.find(x) == visited.end()) {
                q.push(x);
                visited.insert(x);
            }
        }
    }

    return visited.size() == rooms.size();
}

int main() {
    vector<vector<int>> rooms = {{1,3}, {3,0,1}, {2}, {0}};
    bool ans = canVisitAllRooms(rooms);
    cout << ans ;
    return 0;
}

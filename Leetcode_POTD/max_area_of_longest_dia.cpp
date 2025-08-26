/*
## 3000. Maximum Area of Longest Diagonal Rectangle
Statement : You are given a 2D 0-indexed integer array dimensions.
For all indices i, 0 <= i < dimensions.length, dimensions[i][0] represents the length and dimensions[i][1] represents the width of the rectangle i.

Return the area of the rectangle having the longest diagonal. If there are multiple rectangles with the longest diagonal, return the area of the rectangle having the maximum area.
1. Input: dimensions = [[9,3],[8,6]]
   Output: 48
2. Input: dimensions = [[3,4],[4,3]]
   Output: 12
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
    int n = dimensions.size();
    priority_queue<pii, vector<pii>, greater<pii>> pq; // (diagonal length, area)
    for(int i = 0; i < n; i++){
        int len = dimensions[i][0];
        int wid = dimensions[i][1];
        int diagonal = len * len  +  wid * wid;
        int area = len * wid;
        pq.push({diagonal, area});
        if(pq.size() > 1) pq.pop();
    }
    
    return pq.top().second;
}

int main(){
    vector<vector<int>> dimensions = {{9,3}, {8,6}};
    cout << areaOfMaxDiagonal(dimensions);
}


#include <bits/stdc++.h>
using namespace std;

// Function to return the cost of the minimum cost path
// from (0,0) to (m - 1, n - 1) in a cost matrix
int findMinCost(vector<vector<int>>& cost, int x, 
                int y, vector<vector<int>> &memo) {
    int m = cost.size();
    int n = cost[0].size();
  
    // If indices are out of bounds, return a large value
    if (x >= m || y >= m) {
        return INT_MAX;
    }

    // Base case: bottom cell
    if (x == m - 1 && y == n - 1) {
        return cost[x][y];
    }

    // Check if the result is already computed
    if (memo[x][y] != -1) {
        return memo[x][y];
    }

    // Recursively calculate minimum cost from 
    // all possible paths
    return memo[x][y] = cost[x][y] + 
        min({findMinCost(cost, x, y + 1, memo), 
            findMinCost(cost, x + 1, y, memo), 
            findMinCost(cost, x + 1, y + 1, memo)}); 
}

// function to find the minimum cost path
// to reach (m - 1, n - 1) from (0, 0)
int minCost(vector<vector<int>>& cost) {
    int m = cost.size();
    int n = cost[0].size();

    // create 2d array to store the minimum cost path
    vector<vector<int>> memo(m, vector<int>(n, -1));
    return findMinCost(cost, 0, 0, memo);
}

int main() {
    vector<vector<int>> cost = {
        { 1, 2, 3 },
        { 4, 8, 2 },
        { 1, 5, 3 } 
    };
    cout << minCost(cost);
    return 0;
}
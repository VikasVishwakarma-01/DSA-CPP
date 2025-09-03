// C++ implementation to find the minimum cost path
// using Space Optimization
#include <bits/stdc++.h>
using namespace std;

int minCost(vector<vector<int>> &cost) {
  
    int m = cost.size();
    int n = cost[0].size();

    // 1D dp array to store the minimum cost
  	// of the current row
    vector<int> dp(n, 0);

    // Initialize the base cell
    dp[0] = cost[0][0];

    // Fill the first row
    for (int j = 1; j < n; j++) {
        dp[j] = dp[j - 1] + cost[0][j];
    }

    // Fill the rest of the rows
    for (int i = 1; i < m; i++) {
      
        // Store the previous value of dp[j-1] 
      	// (for diagonal handling)
        int prev = dp[0];

        // Update the first column (only depends on
      	// the previous row)
        dp[0] = dp[0] + cost[i][0];

        for (int j = 1; j < n; j++) {
          
            // Store the current dp[j] before updating it
            int temp = dp[j];

            // Update dp[j] using the minimum of the
          	// top, left, and diagonal cells
            dp[j] = cost[i][j] + min({dp[j], dp[j - 1], prev});

            // Update prev to be the old dp[j] for the
          	// diagonal calculation in the next iteration
            prev = temp;
        }
    }

    // The last cell contains the 
  	// minimum cost path
    return dp[n - 1];
}

int main() {
    vector<vector<int>> cost = {{1, 2, 3}, {4, 8, 2}, {1, 5, 3}};

    cout << minCost(cost) << endl;
    return 0;
}
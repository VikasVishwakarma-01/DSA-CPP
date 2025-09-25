class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp = grid;
        
        for(int i = 1; i < m; i++) {
            dp[0][i] += dp[0][i-1];
        }

        for(int j = 1; j < n; j++) {
            dp[j][0] += dp[j-1][0];
        }

        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                dp[i][j] += min(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[n-1][m-1];
    }

};
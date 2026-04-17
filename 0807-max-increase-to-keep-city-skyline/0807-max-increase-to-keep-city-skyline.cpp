class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int ans = 0;
        vector<vector<int>> mat = grid;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int x = INT_MIN;

                for(int k = 0; k < n; k++)
                    x = max(x, mat[i][k]);

                int y = INT_MIN;

                for(int k = 0; k < m; k++)
                    y = max(y, mat[k][j]);

                mat[i][j] = min(x, y);
                ans += (mat[i][j] - grid[i][j]);
                
            }
        }

        return ans;
    }
};
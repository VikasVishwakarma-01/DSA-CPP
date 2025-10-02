class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        unordered_map<int, int> row0;
        unordered_map<int, int> row1;
        unordered_map<int, int> col0;
        unordered_map<int, int> col1;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m; i++) {
            int one = 0;
            int zero = 0;
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) zero++;
                if(grid[i][j] == 1) one++;
            }
            row0[i] = zero;
            row1[i] = one;
        }

        for(int i = 0; i < n; i++) {
            int one = 0;
            int zero = 0;
            for(int j = 0; j < m; j++) {
                if(grid[j][i] == 0) zero++;
                if(grid[j][i] == 1) one++;
            }
            col0[i] = zero;
            col1[i] = one;
        }
        vector<vector<int>> ans(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int diff = row1[i] + col1[j] - row0[i] - col0[j];
                ans[i][j] = diff;
            }
        }

        return ans;
    }
};
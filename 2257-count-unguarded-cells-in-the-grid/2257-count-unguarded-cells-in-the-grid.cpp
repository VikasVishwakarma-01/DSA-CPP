class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, -1)); // -1 empty, 0 wall, 1 guard, 2 guarded

        for (auto &w : walls) grid[w[0]][w[1]] = 0;
        for (auto &g : guards) grid[g[0]][g[1]] = 1;

        // Row sweeps
        for (int i = 0; i < m; i++) {
            bool seen = false;
            // left -> right
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) seen = false;
                else if (grid[i][j] == 1) seen = true;
                else if (seen) grid[i][j] = 2;
            }
            seen = false;
            // right -> left
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 0) seen = false;
                else if (grid[i][j] == 1) seen = true;
                else if (seen) grid[i][j] = 2;
            }
        }

        // Column sweeps
        for (int j = 0; j < n; j++) {
            bool seen = false;
            // top -> bottom
            for (int i = 0; i < m; i++) {
                if (grid[i][j] == 0) seen = false;
                else if (grid[i][j] == 1) seen = true;
                else if (seen) grid[i][j] = 2;
            }
            seen = false;
            // bottom -> top
            for (int i = m - 1; i >= 0; i--) {
                if (grid[i][j] == 0) seen = false;
                else if (grid[i][j] == 1) seen = true;
                else if (seen) grid[i][j] = 2;
            }
        }

        int ans = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == -1)
                    ans++;

        return ans;
    }
};

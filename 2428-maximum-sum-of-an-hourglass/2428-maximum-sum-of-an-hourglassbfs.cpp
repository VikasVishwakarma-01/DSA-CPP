class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int maxSum = 0;
        for(int i = 0; i < n - 2; i++) {
            for(int j = 0; j < m - 2; j++) {
                int sum = 0;

                for(int k = j; k < j + 3; k++) 
                    sum += grid[i][k];

                sum += grid[i+1][j+1];

                for(int k = j; k < j + 3; k++) 
                    sum += grid[i+2][k];

                maxSum = max(maxSum, sum);
            }
        }

        return maxSum;
    }
};
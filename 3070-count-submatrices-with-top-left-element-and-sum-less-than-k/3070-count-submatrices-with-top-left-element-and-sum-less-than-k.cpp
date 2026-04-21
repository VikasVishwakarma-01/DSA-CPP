class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        int sum = 0;
        sum += grid[0][0];
        if(sum > k) 
            return 0;
        
        int cnt = 1;
        for(int i = 1; i < m; i++) {
            sum += grid[0][i];
            if(sum > k)
                break;
            else cnt++;
        }
        
        sum = grid[0][0];
        for(int j = 1; j < n; j++) {
            sum += grid[j][0];
            if(sum > k)
                break;
            else cnt++;
        }
       
        for(int i = 0; i < n; i++) {
            for(int j = 1; j < m; j++) {
                grid[i][j] = grid[i][j] + grid[i][j-1];
            }
        }

        for(int j = 1; j < m; j++) {
            int s = grid[0][j];
            for(int i = 1; i < n; i++) {
                s += grid[i][j];
                if(s > k)
                    break;
                else cnt++;
            }
        }
        
        return cnt;
    }
};
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        long long ans = 0;
        int no_zeroes = 0, no_neg = 0, min_ele = INT_MAX;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                ans += abs(matrix[i][j]);
                if(matrix[i][j] == 0)
                    no_zeroes++;
                if(matrix[i][j] != 0) {
                    min_ele = min(min_ele, abs(matrix[i][j]));
                }
                if(matrix[i][j] < 0) {
                    no_neg++;
                }
            }
        }

        if(no_zeroes == 0) {
            if(no_neg % 2 != 0) 
                ans -= abs(min_ele) * 2;
        }
        
        return ans;
    }
};
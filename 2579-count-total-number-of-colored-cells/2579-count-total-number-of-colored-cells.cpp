class Solution {
public:
    long long coloredCells(int n) {
        vector<long long> ans(n);
        ans[0] = 1;
        long long x = 4;
        for(int i = 1; i < n; i++) {
            ans[i] = ans[i-1] + (long long)x * i;
        }

        return ans[n-1];
    }
};
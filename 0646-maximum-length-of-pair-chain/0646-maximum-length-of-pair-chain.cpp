class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        if(n == 1) return 1;
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        

        int ans = 1;
        int b = pairs[0][1];
        for(int i = 1; i < n; i++) {
            int c = pairs[i][0];
            if(b < c) {
                ans++;
                b = pairs[i][1];
            }
        }

        return ans;
    }
};
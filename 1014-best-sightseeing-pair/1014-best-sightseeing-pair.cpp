class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        vector<int> dp(n);
        for(int i = 0; i < n-1; i++) {
            int curr = values[i];
            int sum = 0;
            for(int j = i+1; j < n; j++) {
                int next = values[j];
                sum = max(sum, curr + next + i - j);
            }
            dp[i] = sum;
        }

        return *max_element(dp.begin(), dp.end());
    }
};
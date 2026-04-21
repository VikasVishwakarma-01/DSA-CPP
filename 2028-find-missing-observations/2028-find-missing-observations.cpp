class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum = 0;
        int m = rolls.size();

        for(int x : rolls) sum += x;

        int total = mean * (m + n);
        int missing_sum = total - sum;

        if(missing_sum < n || missing_sum > 6*n)
            return {};

        vector<int> ans(n, missing_sum / n);

        int rem = missing_sum % n;

        for(int i = 0; i < rem; i++) {
            ans[i]++;
        }

        return ans;
    }
};
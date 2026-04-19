class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        int n = nums.size();

        long long ans = 0;
        int x = nums[0];
        int idx = -1;
        int k = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] > x) {
                ans += 1LL*(i - k) * x;
                x = nums[i];
                k = i;
            }

        }

        if(k != n-1) {
            ans += 1LL*(n - 1 - k) * x;
        }

        return ans;
    }
};
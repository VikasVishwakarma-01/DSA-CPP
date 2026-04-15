class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<long long> pre(n);
        pre[0] = nums[0];

        for(int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] + nums[i];
        }

        vector<long long> ans;

        for(int q : queries) {
            int idx = lower_bound(nums.begin(), nums.end(), q) - nums.begin();

            // Left side
            long long left = 0;
            if(idx > 0) {
                left = (long long)q * idx - pre[idx - 1];
            }

            // Right side
            long long right = 0;
            if(idx < n) {
                right = (pre[n - 1] - (idx > 0 ? pre[idx - 1] : 0)) - (long long)q * (n - idx);
            }

            ans.push_back(left + right);
        }

        return ans;
    }
};
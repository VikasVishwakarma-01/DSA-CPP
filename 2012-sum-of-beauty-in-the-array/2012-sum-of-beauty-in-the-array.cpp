class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n), suf(n);

        pre[0] = nums[0];
        for(int i = 1; i < n; i++) {
            pre[i] = max(pre[i-1], nums[i]);
        }

        suf[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; i--) {
            suf[i] = min(nums[i], suf[i+1]);
        }

        int ans = 0;
        for(int i = 1; i < n-1; i++) {
            if(nums[i] > pre[i-1] && nums[i] < suf[i+1])
                ans += 2;
            
            else if(nums[i] > nums[i-1] && nums[i] < nums[i+1])
                ans += 1;
            
            else ans += 0;
        }

        return ans;
    }
};
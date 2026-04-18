class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();

        vector<int> pre(n), suf(n);
        pre[0] = nums[0];
        for(int i = 1; i < n; i++) {
            pre[i] = max(nums[i], pre[i-1]);
        }
        
        suf[n-1] = nums[n-1];
        for(int j = n-2; j >= 0; j--) {
            suf[j] = min(nums[j], suf[j+1]);
        }

        for(int i = 0; i < n-1; i++) {
            if(pre[i] <= suf[i+1])
                return i+1;
        }

        return n;
    }
};
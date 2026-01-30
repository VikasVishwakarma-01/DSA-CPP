class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        if(n == 1) return 0;
        for(int i = n-1; i > 0; i--) {
            cnt++;
            if(nums[i] <= nums[i-1])
                break;
            if(nums[i] > nums[i-1] && i == 1)
                cnt++;
        }

        return n-cnt;
    }
};
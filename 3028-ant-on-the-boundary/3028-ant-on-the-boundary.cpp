class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int n = nums.size();

        for(int i = 1; i < n; i++)
            nums[i] += nums[i-1];
        
        int cnt = 0;
        for(int i = 0; i < n; i++)
            if(nums[i] == 0) cnt++;

        return cnt;
    }
};
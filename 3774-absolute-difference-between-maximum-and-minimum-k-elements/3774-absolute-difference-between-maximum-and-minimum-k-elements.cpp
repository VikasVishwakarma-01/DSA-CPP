class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        int n = nums.size(), l = 0, s = 0;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < k; i++)
            s += nums[i];

        reverse(nums.begin(), nums.end());

        for(int i = 0; i < k; i++)
            l += nums[i];
        
        return abs(l-s);
    }
};
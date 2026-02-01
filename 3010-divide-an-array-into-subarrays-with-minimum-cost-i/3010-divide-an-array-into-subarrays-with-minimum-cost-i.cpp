class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int x = nums[0];
        int n = nums.size();
        sort(nums.begin() + 1, nums.end());
        int y = nums[1];
        int z = nums[2];

        return x + y + z;
    }
};
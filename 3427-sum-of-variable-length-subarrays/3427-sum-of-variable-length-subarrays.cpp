class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int n = nums.size();
        vector<int> v = nums;
        for(int i = 1; i < n; i++)
            nums[i] += nums[i-1];

        int sum = 0;
        for(int i = 0; i < n; i++) {
            int start = max(0, i - v[i]);
            int end = i;
            (start > 0) ? sum += (nums[end] - nums[start-1]) : sum += nums[end];
        }

        return sum;
    }
};
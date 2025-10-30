class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n = nums.size();
        
        for(int i = 1; i < n; i++) {
            nums[i] += nums[i-1];
        }

        int temp = INT_MAX;
        for(int i = 0; i < n; i++) {
            temp = min(temp, nums[i]);
        }

        if(temp > 0) return 1;
        return abs(temp) + 1;
    }
};
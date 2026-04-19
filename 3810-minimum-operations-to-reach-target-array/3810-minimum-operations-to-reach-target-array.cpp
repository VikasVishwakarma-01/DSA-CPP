class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {
        
        int n = nums.size();

        unordered_set<int> set;
        for(int i = 0; i < n; i++) {
            if(nums[i] != target[i])
                set.insert(nums[i]);
        }

        return set.size();
    }
};
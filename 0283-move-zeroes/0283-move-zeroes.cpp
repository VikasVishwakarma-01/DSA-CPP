class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> v(nums.size(), 0);
        vector<int> idx;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 0) idx.push_back(nums[i]);
        }
        for(int i = 0; i < idx.size(); i++) {
            v[i] = idx[i];
        }
        nums = v;
        return;
    }
};
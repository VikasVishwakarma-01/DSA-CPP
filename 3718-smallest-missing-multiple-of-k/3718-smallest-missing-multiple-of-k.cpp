class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> set(nums.begin(), nums.end());
        for(int i = 1; i <= 200; i++) {
            int x = k*i;
            if(set.find(x) == set.end()) return x;
        }

        return 0;
    }
};
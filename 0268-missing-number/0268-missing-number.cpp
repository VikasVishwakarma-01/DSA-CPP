class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_set<int> set;

        int n = nums.size();
        for(int i = 0; i <= n; i++) {
            set.insert(i);
        }

        for(int a: nums) {
            set.erase(a);
        }

        for(auto x: set) {
            return x;
        }

        return 0;
    }

};
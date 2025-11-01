class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        unordered_set<int> set(nums.begin(), nums.end());
        vector<int> vec(set.begin(), set.end());
        sort(vec.begin(), vec.end());

        int maxCurr = 1, curr = 1;

        for (int i = 1; i < vec.size(); i++) {
            if (vec[i] == vec[i-1] + 1) {
                curr++;
            } else {
                maxCurr = max(maxCurr, curr);
                curr = 1;
            }
        }

        return max(maxCurr, curr);
    }
};

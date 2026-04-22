class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        int n = nums.size();

        unordered_set<int> set;
        for(int i = 0; i < n; i++)
            set.insert(nums[i]);

        int m = moveFrom.size();
        for(int i = 0; i < m; i++) {
            int initial = moveFrom[i];
            int final = moveTo[i];
            set.erase(initial);
            set.insert(final);
        }
        
        vector<int> ans(set.begin(), set.end());
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};
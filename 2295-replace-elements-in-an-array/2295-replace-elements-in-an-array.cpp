class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int, int> mp;

        int n = nums.size();
        for(int i = 0; i < n; i++) {
            mp[nums[i]] = i;
        }

        for(int i = 0; i < operations.size(); i++) {
            int pre = operations[i][0];
            int now = operations[i][1];
            int idx = mp[pre];
            mp.erase(pre);
            mp[now] = idx;
        }

        vector<int> result(n);
        for(auto p: mp) {
            int val = p.first;
            int idx = p.second;
            result[idx] = val;
        }

        return result;
    }
};
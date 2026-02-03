class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]] = i;
        }

        for(int i = 0; i < nums.size(); i++) {
            int n = target - nums[i];
            if(mp.find(n) != mp.end() && i != mp[n]) {
                ans.push_back(i);
                ans.push_back(mp[n]);
                break;
            }
        }

        return ans;
    }
};
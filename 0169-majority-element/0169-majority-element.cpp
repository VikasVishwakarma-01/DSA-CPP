class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;

        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        int n = nums.size();
        for(auto p: mp) {
            int val = p.first;
            int freq = p.second;
            if(freq > n/2) return val;
        }

        return 0;
    }
};
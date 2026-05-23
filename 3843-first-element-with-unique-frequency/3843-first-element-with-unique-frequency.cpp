class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto x: nums) mp[x]++;

        unordered_map<int, int> mp2;
        for(auto p: mp) {
            int val = p.first;
            int f = p.second;
            mp2[f]++;
        }

        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int f1 = mp[nums[i]];
            int f2 = mp2[f1];
            if(f2 == 1)
                return nums[i];
        }

        return -1;
    }
};
class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_map<int, int> mp;

        for(auto x: nums) {
            mp[x]++;
        }

        int ans = 0;
        for(auto x: mp) {
            int key = x.first;
            int freq = x.second;

            if(freq == 2)
                ans ^= key;
        }

        return ans;
    }
};
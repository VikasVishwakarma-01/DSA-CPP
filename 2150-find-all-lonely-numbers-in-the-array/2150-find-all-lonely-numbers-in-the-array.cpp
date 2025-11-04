class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int, int> mp;
        unordered_map<int, int> mp2;
        for(auto x: nums) {
            mp[x]++;
            mp2[x]++;
        }
        
        vector<int> ans;
        for(auto x: mp) {
            int val = x.first;
            if(x.second == 1) 
                if((mp2.find(val-1) == mp2.end()) && (mp2.find(val+1) == mp2.end()))
                    ans.push_back(x.first);
        }

        return ans;
    }
};
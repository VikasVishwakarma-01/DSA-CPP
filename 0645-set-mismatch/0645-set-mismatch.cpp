class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,int> mp;
        unordered_set<int> set;

        int d;
        int m;
        for(auto x: nums) {
            mp[x]++;
            set.insert(x);
            if(mp[x] == 2) 
                d = x;
        }

        for(int i = 1; i <= nums.size(); i++) {
            if(set.find(i) == set.end()) {
                m = i;
                break;
            }
        }

        return {d, m};
    }
};
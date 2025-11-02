class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;

        for(int i = 0; i < n; i++) 
            mp[nums[i]]++;

        vector<pair<int, int>> v;
        for(auto p: mp) 
            v.push_back(p);
        
        sort(v.begin(), v.end());
        
        int curr = 0, op = 0, m = v.size();
        for(int i = m-1; i >= 1; i--) {
            curr += v[i].second;
            op += curr;
        }

        return op;
    }
};
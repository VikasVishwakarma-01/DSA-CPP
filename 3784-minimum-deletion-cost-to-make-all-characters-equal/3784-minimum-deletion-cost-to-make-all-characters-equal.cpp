class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        long long sum = 0;
        long long ans = 0;

        unordered_map<char, long long> mp;

        int n = s.length();
        for(int i = 0; i < n; i++) {
            if(mp.find(s[i]) != mp.end()) {
                mp[s[i]] += cost[i];
            }
            else {
                mp[s[i]] = cost[i];
            }
        }
        if(mp.size() == 1) 
            return ans;
            
        for(auto x: mp) {
            long long val = x.second;
            sum = (long long)sum + (long long)val;
            if( val > ans) 
                ans = val;
        }
        cout << sum << " " << ans;
        //cout << sum - ans;
        return sum - ans;
    }
};
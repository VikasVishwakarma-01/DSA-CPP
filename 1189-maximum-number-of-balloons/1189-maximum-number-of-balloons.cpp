class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n = text.size();
        unordered_map<char, int> mp;
        unordered_set<char> set;
        string s = "balloon";
        for(int i = 0; i < s.length(); i++) {
            set.insert(s[i]);
        }
        for(int i = 0; i < n; i++) {
            if(set.find(text[i]) != set.end())
                mp[text[i]]++;
        }

        int ans = 0;
        int m = text.length()/s.length();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < s.length(); j++) {
                if(mp.find(s[j]) != mp.end()) {
                    mp[s[j]]--;
                    if(mp[s[j]] == 0) 
                        mp.erase(s[j]);
                }
                else return ans;
            }
            ans++;
        }

        return ans;
    }
};
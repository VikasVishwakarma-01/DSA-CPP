class Solution {
public:
    string lastNonEmptyString(string s) {
        unordered_map<char, int> mp;

        int x = 0;
        for(auto &ch: s) {
            mp[ch]++;
            x = max(x, mp[ch]);
        }

        int n = s.length();
        unordered_set<char> set;
        for(auto p: mp) {
            if(p.second == x) 
                set.insert(p.first);
        }
        
        string st = "";
        for(int i = n-1; i >= 0; i--) {
            if(set.find(s[i]) != set.end()) {
                st += s[i];
                set.erase(s[i]);
            }
        }
        
        reverse(st.begin(), st.end());

        return st;
    }
};
class Solution {
public:
    int maximumLength(string s) {
        int n = s.length();

        unordered_map<string, int> mp;
        for(int i = 0; i < n; i++) {
            string str = "";
            for(int j = i; j < n; j++) {
                str += s[j];
                mp[str]++;
            }
        }

        int len = -1;
        for(auto p: mp) {
            string st = p.first;
            int freq = p.second;

            unordered_set<char> set(st.begin(), st.end());
            if(freq >= 3 && (set.size() == 1))
                len = max(len, (int)st.length());
        }

        return len;
    }
};
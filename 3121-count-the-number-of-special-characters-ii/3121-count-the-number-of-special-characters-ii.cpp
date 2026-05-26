
class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char, int> mp;

        int n = word.length();
        for(int i = 0; i < n; i++) {

            char ch = word[i];
            if(ch >= 65 && ch <= 90) 
                if(mp.find(ch) == mp.end()) mp[ch] = i;
        }

        int ans = 0;
        for(int i = n-1; i >= 0; i--) {
            char ch = word[i];
            if(ch >= 97 && ch <= 122) {
                char ch_upper = toupper(ch);
                if(mp.find(ch_upper) != mp.end()) {
                    int idx = mp[ch_upper];
                    if(idx > i) {
                        ans++;
                        mp.erase(ch_upper);
                    }
                    else mp.erase(ch_upper);
                }
            }
        }

        return ans;
    }
};
class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char, int> mp;

        int n = word.length();
        for(auto x: word)
            mp[x]++;
        
        int cnt = 0;
        for(auto x: word) {
            if(x >= 97 && x <= 122) {
                
                char ch = toupper(x);
                if(mp.find(ch) != mp.end()) {
                    cnt++;
                    mp.erase(ch);
                }
            }
        }
        return cnt;
    }
};
class Solution {
public:
    long long calculateScore(string s) {
        int n = s.length();
        map<char, vector<int>> mp;

        mp[s[0]].push_back(0);

        long long ans = 0;
        for(int i = 1; i < n; i++) {
            char ch = s[i];
            char mirrorCh = 'a' + ('z' - ch);
            if(mp.find(mirrorCh) != mp.end()) {
                int idx = mp[mirrorCh].back();
                mp[mirrorCh].pop_back();
                if(mp[mirrorCh].size() == 0)
                    mp.erase(mirrorCh);
                
                ans += (i - idx);
            }
            else
                mp[s[i]].push_back(i);
        }

        return ans;
    }
};
class Solution {
public:
    int minimumSwap(string s1, string s2) {
        unordered_map<char, int> mp;

        int n = s1.length();
        for(int i = 0; i < n; i++) {
            mp[s1[i]]++;
            mp[s2[i]]++;
        }

        for(auto [ch, x]: mp) {
            if(x % 2 != 0)
                return -1;
        }

        int xy=0, yx=0;
        for(int i = 0; i < n; i++) {
            if(s1[i]=='x' && s2[i]=='y') 
                xy++;
            else if(s1[i]=='y' && s2[i]=='x')
                yx++;
        }

        return xy/2 + yx/2 + (xy%2) * 2;
    }
};
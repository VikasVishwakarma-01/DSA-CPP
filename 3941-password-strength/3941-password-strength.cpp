class Solution {
public:
    int passwordStrength(string password) {
        int n = password.length();
        int ans = 0;

        unordered_map<char, int> mp;
        for(int i = 0; i < n; i++) {
            mp[password[i]]++;
        }

        for(auto p: mp) {
            char ch = p.first;
            if(ch >= 'a' && ch <= 'z')
                ans += 1;
            
            else if(ch >= 'A' && ch <= 'Z') 
                ans += 2;
            

            else if(ch >= '0' && ch <= '9') 
                ans += 3;

            else ans += 5;
            
        }

        return ans;
    }
};
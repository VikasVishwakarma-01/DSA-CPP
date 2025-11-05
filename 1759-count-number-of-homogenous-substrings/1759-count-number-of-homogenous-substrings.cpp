class Solution {
public:
    int countHomogenous(string s) {
        int n = s.length();
        const int mod = 1000000007;
        int ans = 1;
        int cnt = 1;
        for(int i = 1; i < n; i++) {
            if(s[i] == s[i-1]) {
                cnt++;
                ans = (ans % mod + cnt % mod) % mod;
            }
            else {
                cnt = 1;
                ans = (ans % mod + cnt % mod) % mod;
            }
        }

        return ans % mod;
    }
};
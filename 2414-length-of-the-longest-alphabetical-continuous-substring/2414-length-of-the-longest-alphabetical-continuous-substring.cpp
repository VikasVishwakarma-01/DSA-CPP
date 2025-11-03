class Solution {
public:
    int longestContinuousSubstring(string s) {
        int n = s.length();

        int maxAns = 0, ans = 0;
        for(int i = 0; i < n - 1; i++) {
            if(s[i + 1] - s[i] == 1) 
                ans++;
            else {
                maxAns = max(maxAns, ans);
                ans = 0;
            }
        }

        maxAns = max(maxAns, ans);

        return maxAns + 1;
    }
};
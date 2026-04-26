class Solution {
public:
    long long minimumSteps(string s) {
        long long ans = 0;
        long long cnt = 0;
        int idx = 0;
        int n = s.length();
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') {
                idx = i;
                break;
            }
        }

        for(int i = idx; i < n; i++) {
            if(s[i] == '1') cnt++;
            else ans += cnt;
        }

        return ans;
    }
};
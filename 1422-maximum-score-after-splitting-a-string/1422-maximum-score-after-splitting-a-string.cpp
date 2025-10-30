class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        vector<int> v(n);
        for(int i = 0; i < n; i++) {
            if(s[i] == '0') v[i] = 0;
            else v[i] = 1;
        }

        vector<int> prefix_zero(n, 0);
        vector<int> suffix_one(n, 0);
        
        if(v[0] == 0) prefix_zero[0] = 1;
        for(int i = 1; i < n; i++) {
            if(v[i] == 0) {
                prefix_zero[i] += prefix_zero[i-1];
                prefix_zero[i]++;
            }
            else prefix_zero[i] += prefix_zero[i-1];
        }

        if(v[n-1] == 1) suffix_one[n-1] = 1;
        for(int i = n-2; i >= 0; i--) {
            if(v[i] == 1) {
                suffix_one[i] += suffix_one[i+1];
                suffix_one[i]++;
            }
            else suffix_one[i] += suffix_one[i+1];
        }

        int ans = 0;
        for(int i = 0; i < n-1; i++) {
            ans = max(ans ,(prefix_zero[i] + suffix_one[i+1]));
        }
        if(prefix_zero[n-1] == 0) return suffix_one[1];
        if(suffix_one[0] == 0) return prefix_zero[n-2];

        return ans;
    }
};
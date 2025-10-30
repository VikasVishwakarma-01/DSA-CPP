class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        vector<int> v(n, 1);
        const int mod = 1000000007;
        for(int i = 1; i <= k; i++) {
            for(int j = 1; j < v.size(); j++) {
                v[j] = (v[j] % mod) + (v[j-1] % mod);
            }
        }

        return v[n-1] % mod;
    }
};
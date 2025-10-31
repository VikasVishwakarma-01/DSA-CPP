class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        const int mod = 1000000007;

        int even = 1, odd = 0, ans = 0, pre = 0;
        for(int i = 0; i < n; i++) {
            pre += arr[i];

            if(pre % 2 == 0) {
                ans = (ans + odd) % mod;
                even++;
            }

            else {
                ans = (ans + even) % mod;
                odd++;
            }
        }

        return ans;
    }
};
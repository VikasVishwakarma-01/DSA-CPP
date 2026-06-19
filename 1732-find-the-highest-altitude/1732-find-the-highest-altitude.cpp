class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        vector<int> v;
        v.push_back(0);
        for(int i = 0;i < n; i++)
            v.push_back(v[i] + gain[i]);

        int ans = INT_MIN;
        for(int i = 0; i < n+1; i++) {
            ans = max(ans, v[i]);
        }

        return ans;
    }
};
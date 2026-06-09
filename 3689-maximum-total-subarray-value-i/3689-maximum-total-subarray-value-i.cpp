class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int x = INT_MAX;
        int y = INT_MIN;
        for(auto n: nums) {
            if(n > y) y = n;
            if(n < x) x = n;
        }

        long long ans = (long long)(y-x);
        return ans*k;
        
    }
};
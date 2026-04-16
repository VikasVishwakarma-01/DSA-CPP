class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) 
            return 1;

        int mx = INT_MIN, mn = INT_MAX;
        int mxidx = -1, mnidx = -1;
        for(int i = 0; i < n; i++) {
            if(nums[i] > mx) {
                mx = nums[i];
                mxidx = i;
            }

            if(nums[i] < mn) {
                mn = nums[i];
                mnidx = i;
            }
           
        }
        int ans = INT_MAX;
        // left to right
        ans = min(ans, max(mxidx, mnidx) + 1);

        // right to left
        ans = min(ans, max(n - mxidx, n - mnidx));

        if(mxidx > mnidx) {
            ans = min(ans, mnidx + 1 + n - mxidx);
            return ans;
        }

        else {
            ans = min(ans, mxidx + 1 + n - mnidx);
            return ans;
        }
        return 0;
    }
};
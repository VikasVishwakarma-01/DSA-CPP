#define ll long long
class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        if(n == 2 )
            return abs(nums[0] - nums[1]);

        vector<long long> pre(n);
        pre[0] = nums[0];
        for(int i = 1; i < n; i++) 
            pre[i] = pre[i-1] + nums[i];

        int l_idx = 0;
        bool left = true;
        for(int i = 0; i < n-1; i++) {
            if(nums[i] >= nums[i+1]) {
                l_idx = i;
                left = false;
                break;
            }
            
        }
        
        bool right = true;
        int r_idx = n-1;
        for(int i = n-1; i > 0; i--) {
            if(nums[i] >= nums[i-1]) {
                r_idx = i;
                right = false;
                break;
            }
        }

        cout << l_idx << " " << r_idx;
        if(left) {
            ll l = pre[n-2], r = pre[n-1] - l, ans = LLONG_MAX;
            ans = min(ans, abs(l-r));
            return ans;
        }

        if(right) {
            ll l = pre[0], r = pre[n-1] - l, ans = LLONG_MAX;
            ans = min(ans, abs(l-r));
            return ans;
        }

        if(l_idx == r_idx) {
            ll l = pre[l_idx], r = pre[n-1] - l, ans = LLONG_MAX;
            ans = min(ans, abs(l-r));
            l = pre[l_idx-1], r = pre[n-1] - l;
            ans = min(ans, abs(l-r));
            return ans;
        }
        else if(l_idx < r_idx && abs(l_idx - r_idx) < 2) {
            ll l = pre[l_idx], r = pre[n-1] - l, ans = LLONG_MAX;
            ans = min(ans, abs(l-r));
            return ans;
        }

        return -1;
    }
};
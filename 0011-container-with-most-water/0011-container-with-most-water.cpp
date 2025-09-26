class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        
        int l = 0, r = n-1;
        while(l < r) {
            int h = min(height[l], height[r]);
            int w = r-l;
            ans = max(ans, h * w);

            int left_h = height[l];
            int right_h = height[r];
            if(left_h > right_h) r--;
            else l++;
        }

        return ans;
    }
};
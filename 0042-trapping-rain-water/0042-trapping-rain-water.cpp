class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> left(n);
        int leftMax = height[0];
        left[0] = height[0];
        for(int i = 1; i < n; i++) {
            left[i] =  leftMax;
            //cout << right_max[i] << " ";
            leftMax = max(leftMax, height[i]);
        }

        vector<int> right(n);
        int rightMax = height[n-1];
        right[n-1] = height[n-1];
        for(int i = n-2; i >= 0; i--) {
            right[i] = rightMax;
            rightMax = max(rightMax, height[i]);
        }
        for(int i = 0; i < n; i++) {
            cout << left[i] << " ";
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int l = left[i];
            int r = right[i];
            int h = height[i];
            (min(l, r) - h) > 0 ? ans += (min(l, r) - h) : ans += 0;
        }

        return ans;
    }
};

// 3 3 3 3 3 3 3 2 2 2 1 1
// 0 0 1 1 2 2 2 2 3 3 3 3 
// 0 
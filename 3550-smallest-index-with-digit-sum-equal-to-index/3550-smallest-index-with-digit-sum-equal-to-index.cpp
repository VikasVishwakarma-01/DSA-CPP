class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int ans = -1;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            int m = nums[i];
            int sum = 0;
            while(m > 0) {
                sum += m % 10;
                m /= 10;
            }

            if(sum == i) {
                ans = i;
                break;
            }
        }

        return ans;
    }
};
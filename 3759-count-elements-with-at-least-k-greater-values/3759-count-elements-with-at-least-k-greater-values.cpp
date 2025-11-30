class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(n == 1 && k == 0) return 1;
        if(k == 0) return n;
        int cnt = 0;
        int c = k;
        for(int i = n-1-k; i >= 0; i--) {
            if(nums[i+1] > nums[i]) {
                cnt++;
                c++;
            }
                
            if(nums[i+1] == nums[i] && c-1 >= k) {
                cnt++;
                c++;
            }
        }

        return cnt;
    }
};
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans = 0;
        int c = 0;
        for(int i = 0; i < nums.size()-1; i++) {
            c += abs(nums[i] - nums[i+1]);
            ans += c;
        }

        return ans;
    }
};
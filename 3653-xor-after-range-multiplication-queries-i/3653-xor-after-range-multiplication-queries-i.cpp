const int MOD = 1000000007; 
class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int ans = 0;
        int n = nums.size();
        for(auto x: queries){
            for(int i = x[0]; i <= x[1]; i += x[2]){
                nums[i] = (1LL * nums[i] * x[3]) % MOD;
            }
        }
        for(int i = 0; i < n; i++){
            ans ^= nums[i];
        }
        return ans;
    }
};
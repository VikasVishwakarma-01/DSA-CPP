class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n = nums.size();
        
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++) {
            int x = nums[i] - i;
            mp[x]++;
        }

        long long cnt = 0;
        for(auto &p: mp) {
            cnt += (p.second * (p.second - 1))/ 2;
        }

        long long ans = n * (n - 1) / 2;
        ans -= cnt;
        
        return ans;
    }
};
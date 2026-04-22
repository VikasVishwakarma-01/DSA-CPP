class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        if(k >= n)
            return n;
        
        unordered_map<int, int> mp;

        int j = 0;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;

            while(mp[nums[i]] > k) {

                mp[nums[j]]--;

                if(mp[nums[j]] == 0)
                    mp.erase(nums[j]);
                
                j++;
            }
            
            ans = max(ans, i - j + 1);
        }

        return ans;
    }
};
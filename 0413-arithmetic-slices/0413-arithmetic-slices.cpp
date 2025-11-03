class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return 0;
       
        vector<int> v;

        for(int i = 0; i < n - 1; i++) 
            v.push_back(nums[i+1] - nums[i]);

        int ans = 0;
        for(int i = 0; i < v.size() - 1; i++) {
            for(int j = i; j < v.size()-1; j++) {
                if(v[j] == v[j+1] )
                    ans++;
                else break;
            }
        }

        return ans;
    }
};
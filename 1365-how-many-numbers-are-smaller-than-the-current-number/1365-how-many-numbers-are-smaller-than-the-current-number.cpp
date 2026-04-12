class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            int small = 0;
            for(int j=0;j<n;j++){
                if(nums[i]>nums[j]) small++;
            }
            ans.push_back(small);
            small = 0;
        }
        return ans;
    }
};
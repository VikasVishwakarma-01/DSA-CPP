class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        
        for(int k = 1; k < n-1; k++) {
            if(nums[k] == nums[k+1]) continue;
            if(k < n-2 && nums[k] == nums[k+2]) continue;
            bool left = false, right = false;
            for(int i = 0; i < k; i++) {
                if(nums[i] < nums[k]) {
                    left = true;
                    break;
                }
            }

            for(int j = k+1; j < n; j++) {
                if(nums[j] > nums[k]){
                    right = true;
                    break;
                }
            }
            if(left && right) return true;
        }

        return false;
    }
};
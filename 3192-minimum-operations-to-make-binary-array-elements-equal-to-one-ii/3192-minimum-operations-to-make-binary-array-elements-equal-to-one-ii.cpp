class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int zero = 0, one = 0;

        int prev;
        int idx = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) {
                prev = 0;
                idx = i;
                zero++;
                break;
            }
        }

        for(int i = idx + 1; i < n; i++) {
            if(nums[i] != prev) {
                if(nums[i] == 1)
                    one++;
                else zero++;

                prev = nums[i];
            }
        }

        if(one == 1 && zero == 0)
            return 0;
            
        return one + zero;
    }
};
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        int one = INT_MAX, two = INT_MAX;
        for(int num: nums) {
            if(num <= one) one = num;
            else if(num <= two) two = num;
            else return true;
        }

        return false;
        /*
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
        */
    }
};

/*
Approach : we need to find only one triplet which is increasing so the intuition is to find two no which are increasing and if we get third then the no exist and return true else false
for example {1, 2, 1, 3}
here we go from idx 0 to 3 --> 
1 is 1st smallest
2 is 2nd smallest
1 is 1st smallest
3 is 3rd smallest return true

*/
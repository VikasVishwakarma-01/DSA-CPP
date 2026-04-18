class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int n = nums.size();
        int x = 0, y = 0;
        int cnt = 1;
        bool one = true, two = false;
        for(int i = 0; i < n; i++) {

            if(nums[i] % 2 != 0) {
                swap(one, two);
            }

            if(cnt % 6 == 0) {
                swap(one, two);
                
            }
           

            if(one) {
                x += nums[i];
            }
            
            if(two) 
                y += nums[i];
                
            cnt++;
            
        }
        
        return x - y;
    }
};
class Solution {
public:
   
    vector<int> rotateElements(vector<int>& nums, int k) {
        int n = nums.size();

        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(nums[i] >= 0) {
                q.push(nums[i]);
            }
        }

        int m = q.size();
        if(m == 0) return nums;

        int r = k % m;
        while(r > 0) {
            int ele = q.front();
            cout<<ele;
            q.pop();
            q.push(ele);
            r--;
        }

        for(int i = 0; i < n; i++) {
            if(nums[i] >= 0) {
                nums[i] = q.front();
                q.pop();
            }
        }

        return nums;
        
    }
};
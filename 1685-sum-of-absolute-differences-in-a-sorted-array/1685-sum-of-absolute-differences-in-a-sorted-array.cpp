class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();

        vector<int> pre(n);

        pre[0] = nums[0];
        for(int i = 1; i < n; i++)
            pre[i] = pre[i-1] + nums[i];

        vector<int> result(n, 0);

        for(int j = 0 ; j < n; j++) {

            int left = 0, right = 0;

            if(j > 0)
                left = j * nums[j] - pre[j-1];
            
            if(j < n-1) 
                right = pre[n-1] - pre[j] - (n - 1 - j) * nums[j];

            result[j] = left + right;
        }

        return result;
    }
};
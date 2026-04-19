class Solution {
public: 
    void print(vector<int> v) {
        for(int i = 0; i < v.size(); i++) {
            cout<< v[i] << " ";
        }
        cout<<endl;
    }
    long long minOperationsToMakeMedianK(vector<int>& v, int k) {
        vector<int> nums = v;
        sort(nums.begin(), nums.end());
        sort(v.begin(), v.end());
        int n = nums.size();
        long long ops = 0;

        if(nums[n/2] == k) 
        return 0;
        
        nums[n/2] = k;
        for(int i = n/2; i > 0; i--) {
            if(nums[i-1] > nums[i])
                nums[i-1] = nums[i];
        }

        for(int i = n/2; i < n-1; i++) {
            if(nums[i] > nums[i+1])
                nums[i+1] = nums[i];
            
        }
        
        for(int i = 0; i < n; i++) {
            ops += abs(nums[i] - v[i]) * 1LL;
        }

        return ops;
    }
};
class NumArray {
public:
    vector<int> pre;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        pre = nums;
        for(int i = 1; i < n; i++) {
            pre[i] += pre[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        return (left > 0) ? pre[right] - pre[left-1] : pre[right];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
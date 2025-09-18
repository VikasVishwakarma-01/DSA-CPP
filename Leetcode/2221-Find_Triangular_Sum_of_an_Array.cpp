#include <bits/stdc++.h>
using namespace std;

int triangularSum(vector<int>& nums) {
    if(nums.size() == 1) return nums[0];
    int n = nums.size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < nums.size()-1; j++) {
            if(nums.size() == 1) return nums[0];
            nums[j] = (nums[j] + nums[j+1]) % 10;
        }
        nums.pop_back();
    }

    return nums[0];
}

int main() {
    vector<int> nums = {1,2,3,4,5};
    cout << triangularSum(nums);
}
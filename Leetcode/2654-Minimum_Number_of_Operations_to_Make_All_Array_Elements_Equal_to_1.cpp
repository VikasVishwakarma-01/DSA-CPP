#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int minOperations(vector<int>& nums) {
    int t = INT_MAX, count = 0;
    for(auto n: nums){ if(n == 1) count++; }
    if(count > 0) {
        return nums.size() - count; 
    }
    for(int i = 0; i<nums.size(); ++i ){
        int last = nums[i];
        for(int j = i+1; j < nums.size(); ++j ){
            last = gcd(last, nums[j]);
            if(last == 1) {
                t = min(t, j-i); break; 
            }
        }
    }
    if(t != INT_MAX) return t + nums.size()-1;
    return -1;
}

int main() {
    vector<int> nums = {2,6,3,4};
    cout << minOperations(nums) << endl;
}
#include <bits/stdc++.h>
using namespace std;


int maximumXOR(vector<int>& nums) {
    int ans = 0;
    for (int num : nums) {
        ans |= num;
    }
    return ans;
}

int main() {
    vector<int> nums = {3,2,4,6};
    cout << maximumXOR(nums);
}
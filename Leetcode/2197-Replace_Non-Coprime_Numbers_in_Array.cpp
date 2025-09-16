#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
vector<int> replaceNonCoprimes(vector<int>& nums) {
    vector<int> st;
    
    for (int num : nums) {
        st.push_back(num);
        
        while (st.size() > 1) {
            int a = st.back();
            int b = st[st.size() - 2];
            int g = gcd(a, b);
            
            if (g == 1) break;
            
            long long lcm = (1LL * a * b) / g;
            st.pop_back();
            st.back() = lcm;
        }
    }
    return st;
}

int main() {
    vector<int> nums = {6, 4, 3, 2, 7, 6, 2};
    vector<int> ans = replaceNonCoprimes(nums);

    for(int i = 0; i < ans.size(); i++) {
        cout<< ans[i] <<" ";
    }
}
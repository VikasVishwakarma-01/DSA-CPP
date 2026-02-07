class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int i = left; i <= right; i++) {
            vector<int> digit;
            int n = i;
            while(n > 0) {
                int d = n % 10;
                digit.push_back(d);
                n /= 10;
            }
            bool flag = true;
            for(auto x: digit) {
                if(x == 0 || i % x != 0) {
                    flag = false;
                    break;
                }
            }
            if(flag)
                ans.push_back(i);
        }

        return ans;
    }
};
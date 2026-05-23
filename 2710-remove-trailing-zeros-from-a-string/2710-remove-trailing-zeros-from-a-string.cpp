class Solution {
public:
    string removeTrailingZeros(string num) {
        int n = num.length();
        for(int i = n-1; i >= 0; i--) {
            if(num[i] == '0')
                num.pop_back();
            else break;
        }

        return num;
    }
};
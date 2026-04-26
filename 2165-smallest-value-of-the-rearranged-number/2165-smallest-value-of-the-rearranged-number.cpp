class Solution {
public:
    long long smallestNumber(long long num) {
        if(num == 0) return 0;
        if(num > 0) {
            // smallest
            string s = to_string(num);
            sort(s.begin(), s.end());
            if(s[0] == '0') {
                for(int i = 0; i < s.length(); i++) {
                    if(s[i] != '0') {
                        swap(s[i], s[0]);
                        break;
                    }
                }
            }
            long long ans = stoll(s);
            return ans;
        }
        else {
            // largest
            long long number = abs(num);
            string s = to_string(number);
            sort(s.rbegin(), s.rend());
            long long ans = stoll(s);
            return -ans;
        }

        return 0;
    }
};
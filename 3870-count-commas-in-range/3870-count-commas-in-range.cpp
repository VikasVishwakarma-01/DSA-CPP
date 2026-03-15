class Solution {
public:
    int countCommas(int n) {
        int cnt = 0;
        cnt = n - 1000 + 1;
        if(cnt < 0) 
            return 0;
        return cnt;
    }
};
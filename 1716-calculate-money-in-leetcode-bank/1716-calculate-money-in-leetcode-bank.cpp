class Solution {
public:
    int totalMoney(int n) {
        int ans = 1;
        int m = 1;
        int d = m + 1;
        int cnt = 1;
        for(int i = 2; i <= n; i++) {
            cnt++;
            if(cnt == 8){
                m++;
                ans += m;
                d = m + 1;
                cnt = 1;
            }
            else{
                ans += d;
                d++;
            }
        }

        return ans;
    }
};
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0;
        int n = numBottles;
        int d = numExchange;
        ans += n;
        while(n >= d) {
            ans += n/d;
            int rem = n % d;
            n = (n / d) + rem;
        }
        ans += n/d;
        return ans;
    }
};
/*
ans = 15, n = 15, d = 4,
n = 15, ans = 18, rem = 3, n = 6
n = 6, ans = 19, rem = 2, n = 3
n = 3, ans = 19, rem = 3, 

*/
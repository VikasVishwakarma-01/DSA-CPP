class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = 0;
        int n = numBottles;
        int d = numExchange;
        ans += n;
        while(d <= n) {
            n -= d;
            d++;
            n++;
        }

        return ans+(d-numExchange);
    }
};
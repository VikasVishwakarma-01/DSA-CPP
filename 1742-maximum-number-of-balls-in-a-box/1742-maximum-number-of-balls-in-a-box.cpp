class Solution {
public:
    unordered_map<int, int> mp;
    int calSum(int n) {
        int sum = 0;
        while(n > 0) {
            sum += (n % 10);
            n /= 10;
        }
        return sum;
    }
    int countBalls(int lowLimit, int highLimit) {
        int ans = 0;
        for(int i = lowLimit; i <= highLimit; i++) {
            int digitSum = calSum(i);
            mp[digitSum]++;
            ans = max(ans, mp[digitSum]);
        }
        return ans;
    }
};
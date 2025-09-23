#include <bits/stdc++.h>
using namespace std;

vector<int> dp;
int maxDigit(int n)
{
    int ans = 0;
    while (n > 0)
    {
        int digit = n % 10;
        ans = max(ans, digit);
        n /= 10;
    }
    return ans;
}
int solve(int n)
{
    if (n == 0)
        return 0;
    if (n < 10)
        return 1;

    if (dp[n] != -1)
        return dp[n];

    return dp[n] = 1 + solve(n - maxDigit(n));
}

int solvebu(int n) {
    if (n == 0)
        return 0;
    if (n < 10)
        return 1;

    dp[0] = 0;
    for(int i = 1; i <= 9; i++) dp[i] = 1;
    for(int i = 10; i <= n; i++) {
        int result = INT_MAX;
        int digit = maxDigit(i);
        
    }
}



int solveDP(int n) {

}

int main()
{
    int n;
    cin >> n;
    dp.clear();
    dp.resize(n + 1, -1);
    cout << solve(n) << endl;
}
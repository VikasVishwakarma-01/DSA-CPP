#include <bits/stdc++.h>
using namespace std;

vector<int> dp;

int solve(vector<int> &coins, int n)
{
    if (n == 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    int result = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (n - coins[i] < 0)
            continue;
        result = min(result, solve(coins, n - coins[i]));
    }
    if(result == INT_MAX) return dp[n] = -1;
    return dp[n] = 1 + result;
}

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];
    dp.clear();
    dp.resize(1000006, -1);
    cout << solve(coins, x) << endl;
}
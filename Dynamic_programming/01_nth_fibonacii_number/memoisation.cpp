#include <bits/stdc++.h>
using namespace std;

int nthfib(int n, vector<int>& dp){
    if(n == 0 || n == 1) return n;

    if(dp[n] != -1) return dp[n];

    return dp[n] = nthfib(n-1, dp) + nthfib(n-2, dp);

}

int main(){
    int n = 5;
    vector<int> dp(n+1, -1);
    int ans = nthfib(n, dp);
    cout << ans << endl;
}
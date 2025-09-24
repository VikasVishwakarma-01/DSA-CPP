#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define mod 1000000007

vector<ll> dp(1000005, -1);
int solve(int n) {
    if(n == 0) return 1;
    if(dp[n] != -1) return dp[n];
    ll sum = 0;
    for(int i = 1; i <= 6; i++) {
        if(n-i < 0) break;
        sum = (sum % mod + solve(n-i) % mod) % mod;
    }

    return dp[n] = sum % mod;

    
}

int main() {
    int n = 3;
    cout << solve(n) << endl;
}
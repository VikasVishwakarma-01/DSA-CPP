/**
 * On day 1, one person discovers a secret.

 You are given an integer delay, which means that each person will share the secret with a new person every day, starting from delay days after discovering the secret. You are also given an integer forget, which means that each person will forget the secret forget days after discovering it. A person cannot share the secret on the same day they forgot it, or on any day afterwards.
 
 Given an integer n, return the number of people who know the secret at the end of day n. Since the answer may be very large, return it modulo 109 + 7.

 */

#include <bits/stdc++.h>
using namespace std;

int peopleAwareOfSecret(int n, int delay, int forget) {
    vector<long long> dp(n + 1, 0);
    long long mod = 1e9 + 7;
    
    dp[1] = 1;
    
    long long sharers = 0;
    long long total_aware = 1;

    for(int i = 2; i <= n; ++i) {
        if(i - delay >= 1) {
            sharers = (sharers + dp[i - delay]) % mod;
        }
        
        if(i - forget >= 1) {
            sharers = (sharers - dp[i - forget] + mod) % mod;
        }
        
        dp[i] = sharers;
        total_aware = (total_aware + dp[i]) % mod;

        if(i - forget >= 1) {
            total_aware = (total_aware - dp[i - forget] + mod) % mod;
        }
    }
    
    return total_aware;
}

int main () {
    int n = 6, delay = 2, forget = 4;
    cout << peopleAwareOfSecret(n, delay, forget);
    return 0;
}
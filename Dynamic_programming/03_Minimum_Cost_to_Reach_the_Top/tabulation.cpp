// C++ program to count number of
// ways to reach nth stair.
#include <bits/stdc++.h>
using namespace std;

int minCostClimbingStairs(vector<int> &cost) {
    int n = cost.size();
    
    if (n==1) return cost[0];
    
    vector<int> dp(n);
    dp[0] = cost[0];
    dp[1] = cost[1];
    
    for (int i=2; i<n; i++) {
        dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
    }
    
    return min(dp[n-1], dp[n-2]);
}

int main() {
	vector<int> cost = { 16, 19, 10, 12, 18 };
    cout << minCostClimbingStairs(cost) << endl;
	return 0;
}
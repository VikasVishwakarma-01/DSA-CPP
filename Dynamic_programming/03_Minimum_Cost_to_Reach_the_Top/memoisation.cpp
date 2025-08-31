// C++ program to count number of
// ways to reach nth stair.
#include <bits/stdc++.h>
using namespace std;

int minCostRecur(int i, vector<int> &cost, vector<int> &memo) {
    if (i==0 || i==1) return cost[i];
    
    if (memo[i]!=-1) return memo[i];
    
    return memo[i] = cost[i] + 
    min(minCostRecur(i-1, cost, memo), 
    minCostRecur(i-2, cost, memo));
}

int minCostClimbingStairs(vector<int> &cost) {
    int n = cost.size();
    
    if (n==1) return cost[0];
    
    vector<int> memo(n, -1);
    return min(minCostRecur(n-1, cost, memo), minCostRecur(n-2, cost, memo));
}

int main() {
	vector<int> cost = { 16, 19, 10, 12, 18 };
    cout << minCostClimbingStairs(cost) << endl;
	return 0;
}
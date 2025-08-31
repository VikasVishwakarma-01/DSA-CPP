// C++ program to count number of
// ways to reach nth stair.
#include <bits/stdc++.h>
using namespace std;

int minCostClimbingStairs(vector<int> &cost) {
    int n = cost.size();
    
    if (n==1) return cost[0];

    int prev2 = cost[0];
    int prev1 = cost[1];
    
    for (int i=2; i<n; i++) {
        int curr = cost[i] + 
        min(prev1, prev2);
        
        prev2 = prev1;
        prev1 = curr;
    }
    return min(prev1, prev2);
}

int main() {
	vector<int> cost = { 16, 19, 10, 12, 18 };
    cout << minCostClimbingStairs(cost) << endl;
	return 0;
}
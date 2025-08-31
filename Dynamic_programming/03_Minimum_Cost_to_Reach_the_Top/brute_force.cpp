/*
Given an array of integers cost[] of length n, where cost[i] is the cost of the ith step on a staircase. Once the cost is paid, we can either climb one or two steps.
We can either start from the step with index 0, or the step with index 1. The task is to find the minimum cost to reach the top.

*/
// C++ program to count number of ways to reach nth stair.
#include <bits/stdc++.h>
using namespace std;

int solve(int i, vector<int>& cost){
    if(i == 0 || i == 1) return cost[i];

    return cost[i] + min(solve(i-1, cost), solve(i-2, cost));
}

int minCostClimbingStairs(vector<int>& cost){
    int n = cost.size();

    if( n == 1) return cost[0];

    return min(solve(n-1, cost), solve(n-2, cost));
}

int main() {
	vector<int> cost = { 16, 19, 10, 12, 18 };
    cout << minCostClimbingStairs(cost) << endl;
	return 0;
}
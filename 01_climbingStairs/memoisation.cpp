// C++ program to count number of ways to reach 
// nth stair using memoization

#include <iostream>
#include <vector>
using namespace std;

int countWaysRec(int n, vector<int>& memo) {
  
  	// Base cases
    if (n == 0 || n == 1)
        return 1;

  	// if the result for this subproblem is 
  	// already computed then return it
    if (memo[n] != -1) 
        return memo[n];
    
    return memo[n] = countWaysRec(n - 1, memo) +
      				 	countWaysRec(n - 2, memo);
}

int countWays(int n) {
  
  	// Memoization array to store the results
  	vector<int> memo(n + 1, -1);
  	return countWaysRec(n, memo);
}

int main() {
    int n = 4;
    cout << countWays(n);
    return 0;
}
// C++ program to count number of ways to reach
// nth stair using recursion
#include <iostream>
using namespace std;
int countWays(int n) {

    // Base cases: If there are 0 or 1 stairs,
    // there is only one way to reach the top.
    if (n == 0 || n == 1)
        return 1;
    
    return countWays(n - 1) + countWays(n - 2);
}

int main() {
    int n = 4;
    cout << countWays(n);
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int maxLoot(vector<int>& hval) {
    int n = hval.size();
    vector<int> dp(n+1, 0);
    dp[0] = 0;
    dp[1] = hval[0];
    for (int i = 2; i <= n; i++) 
        dp[i] = max(hval[i - 1] + dp[i - 2], dp[i - 1]);

    return dp[n];
}

int main() {
    vector<int> hval = {6, 7, 1, 3, 8, 2, 4};
    cout << maxLoot(hval) << endl;
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int maxLootRec(vector<int> &hval, vector<int> &dp, int i) {
    int n = hval.size();
    if(i >= n) return 0;
    if(dp[i] != -1) return dp[i];

    int pick = hval[i] + maxLootRec(hval, dp, i+2);
    int notpick = maxLootRec(hval, dp, i+1);
    return dp [i] = max(pick, notpick);
}

int main() {
    vector<int> hval = {6, 7, 1, 3, 8, 2, 4};
    int n = hval.size();
    vector<int> dp(n+1, -1);
    cout << maxLootRec(hval, dp, 0);
    return 0;
}
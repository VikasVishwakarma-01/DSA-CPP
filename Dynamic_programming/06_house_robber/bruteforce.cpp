#include <iostream>
#include <vector>
using namespace std;

int maxLootRec(vector<int> &hval, int i) {
    int n = hval.size();
    if(i >= n) return 0;

    int pick = hval[i] + maxLootRec(hval, i+2);
    int notpick = maxLootRec(hval, i+1);
    return max(pick, notpick);
}

int main() {
    vector<int> hval = {6, 7, 1, 3, 8, 2, 4};
    cout << maxLootRec(hval, 0);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {2, 1, 5, 1, 3, 2};
    int k = 3;

    int n = arr.size();
    vector<int> prefix_sum(n+1, 0);

    for(int i = 0; i < n; i++) {
        prefix_sum[i+1] = prefix_sum[i] + arr[i];
    }

    int max_sum = 0, sum = 0;
    int j = n+1-k;
    
    for(int i = 0; i < j; i++) {
        sum = prefix_sum[i+k] - prefix_sum[i];
        max_sum = max(max_sum, sum);
    }

    cout<< max_sum <<endl;


}
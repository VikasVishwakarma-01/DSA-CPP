#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {2, 1, 5, 1, 3, 2};
    int k = 3;

    int n = arr.size();
    int max_sum = 0, sum = 0;

    for(int i = 0; i < k; i++) {
        sum += arr[i];
    }

    max_sum = max(max_sum, sum);
    for(int i = k; i < n; i++) {
        sum += arr[i];
        sum -= arr[i-k];
        max_sum = max(max_sum, sum);
    }
    cout<<max_sum<<endl;

}
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {2, 1, 5, 1, 3, 2};
    int k = 3;

    int n = arr.size();
    int max_sum = 0;
    for(int i = 0; i < n-k; i++) {
        int sum = 0;

        for(int j = i; j < i+k; j++) {
            sum += arr[j];
        }

        max_sum = max(max_sum, sum);
    }

    cout << max_sum;

}
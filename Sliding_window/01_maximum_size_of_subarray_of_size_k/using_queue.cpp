#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {2, 1, 5, 1, 3, 2};
    int k = 3;

    int n = arr.size();
    queue<int> q;

    int max_sum = 0, sum = 0;
    for(int i = 0 ; i < n; i++) {
        sum += arr[i];
        q.push(arr[i]);
        if(q.size() > k) {
            sum -= q.front();
            q.pop();
        }

        if(q.size() == k) {
            max_sum = max(max_sum, sum);
        }
    }

    cout<< max_sum;


}
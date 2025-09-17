#include <bits/stdc++.h>
using namespace std;

int kthFactor(int n, int k) {
    int ans = 0; 
    for(int i = 1; i <= 1000; i++) {
        if(k == 0) return ans;
        if(n % i == 0){
            ans = i;
            k--;
        }
    }

    return -1;
}


int main() {
    int n = 12, k = 3;
    cout << kthFactor(n, k);
}
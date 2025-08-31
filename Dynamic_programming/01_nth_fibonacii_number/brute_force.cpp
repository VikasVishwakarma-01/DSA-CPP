#include <bits/stdc++.h>
using namespace std;

int nthfib(int n){
    if(n == 1 || n == 0) return n;

    return nthfib(n-1) + nthfib(n-2);
}

int main(){
    int n = 5;
    int ans = nthfib(n);
    cout<< ans <<endl;
}
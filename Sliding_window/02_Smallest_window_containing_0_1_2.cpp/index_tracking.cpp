#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "01212";

    int idx_0, idx_1, idx_2;
    bool zero = false, one = false, two = false;

    int ans = INT_MAX;
    int n = s.length();
    for(int i = 0 ; i < n; i++) {
        if(s[i] == '0') {
            idx_0 = i;
            zero = true;
        }
        else if(s[i] == '1') {
            idx_1 = i;
            one = true;
        }

        else if(s[i] == '2'){
            idx_2 = i;
            two = true;
        }
        
        if(one && two && zero) {
            ans = min(ans, max({idx_0, idx_1, idx_2}) - min({idx_0, idx_1, idx_2}));
        }
    }

    if(ans == INT_MAX) {
        cout<< -1 << endl;
    }
    else cout << ans + 1 <<endl;


}
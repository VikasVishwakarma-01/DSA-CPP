#include <bits/stdc++.h>
using namespace std;



int main() {
    string s = "01212";
    unordered_map<char, int> mp;
    int i = 0;
    int n = s.length();
    int minlen = 0;
    for(int j = 0; j < n; j++){
        mp[s[j]]++;
        while(mp[s[j]] > 1){
            mp[s[i]]--;
            if(mp[s[i]] == 0) mp.erase(s[i]);
            i++;
        }
        minlen = max(minlen, j-i+1);
    }
    cout<< minlen;
    
    return 0;
}
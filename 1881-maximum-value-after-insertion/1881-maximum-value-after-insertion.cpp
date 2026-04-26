class Solution {
public:
    string maxValue(string n, int x) {
        string ans;
        if(n[0] != '-') {
            bool flag = true;
            char ch = x + '0';
            for(int i = 0; i < n.length(); i++) {
                if(flag && n[i] < ch) {
                    ans.push_back(ch);
                    flag = false;
                }
                
                ans.push_back(n[i]);
            }
            if(flag) ans.push_back(ch);
        }
        else {
            ans += '-';
            bool flag = true;
            char ch = x + '0';
            for(int i = 1; i < n.length(); i++) {
                if(flag && n[i] > ch) {
                    ans.push_back(ch);
                    flag = false;
                }
                
                ans.push_back(n[i]);
            }
            if(flag) ans.push_back(ch);
        }

        return ans;
    }
};
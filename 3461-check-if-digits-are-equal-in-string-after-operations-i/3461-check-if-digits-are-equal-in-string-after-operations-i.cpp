class Solution {
public:
    bool hasSameDigits(string s) {
        string t = s;
        for(int j = 0; j < s.size()-2; j++) {
            int n = t.size();
            string nt = "";
            for(int i = 0; i < n - 1; i++) {
                int d1 = t[i] - '0';
                int d2 = t[i+1] - '0';
                char ch = ((d1+d2) % 10) + '0';
                nt += ch;
            }
            t = nt;
            nt = "";
            //cout << t <<endl;
        }
        if(t[0] == t[1]) return true;
        return false;
    }
};
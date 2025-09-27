class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        int n = s1.length();
        int ch = 0;
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        for(int i = 0; i < n; i++) {
            if(s1[i] >= s2[i]) ch++;
        }

        if(ch == n) return true;
        ch = 0;

        for(int i = 0; i < n; i++) {
            if(s2[i] >= s1[i]) ch++;
        }
        if(ch == n) return true;

        return false;
    }
};
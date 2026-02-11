class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        int n = s.length();
        for(int i = 0; i < n; i++) {
            if(s[i] >= 65 && s[i] <= 90)
                str += tolower(s[i]);
            else if((s[i] >= 97 && s[i] <= 122) or (s[i] >= '0' && s[i] <= '9'))
                str += s[i];
            else continue;
        }

        string t = str;

        reverse(str.begin(), str.end());
        cout << str << " "<< t;
        
        if(t == str)
            return true;

        return false;
    }
};
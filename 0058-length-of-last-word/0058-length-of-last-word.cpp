class Solution {
public:
    int lengthOfLastWord(string s) {
        while(s.back() == ' ')
            s.pop_back();
        
        int n = s.length();
        int cnt = 0;
        for(int i = n-1; i >= 0; i--) {
            if(s[i] == ' ')
                break;
            cnt++;
        }

        return cnt;
    }
};
class Solution {
public:
    bool detectCapitalUse(string word) {
        int u = 0;
        int l = 0;
        int n = word.length();

        for(int i = 1; i < n; i++) {
            if(word[i] >= 97 && word[i] <= 122)
                l++;
            else 
                u++;
        }

        int f = int(word[0]);
        if(f <= 90 && u == n-1)
            return true;
        else if(f >= 97 && l == n-1)
            return true;
        else if(f <= 90 && l == n-1)
            return true;
            
        return false;
    }
};
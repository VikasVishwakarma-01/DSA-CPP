class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        int l = 0;
        vector<int> count(3, 0); // counts of 'a', 'b', 'c'
        
        for(int r = 0; r < n; r++) {
            count[s[r] - 'a']++;
            
            // shrink window while it still contains all three
            while(count[0] > 0 && count[1] > 0 && count[2] > 0) {
                count[s[l] - 'a']--;
                l++;
            }
            
            // all substrings ending at r and starting before l are valid
            ans += l;
        }
        
        return ans;
    }
};

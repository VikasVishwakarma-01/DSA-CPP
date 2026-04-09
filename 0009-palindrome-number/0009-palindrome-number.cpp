class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        if(x>-1 && x<10) return true;
        vector<int>ans;
        int digit = 0;
        while(x>0){
            digit = x%10;
            ans.push_back(digit);
            x = x/10;
        }
        int n = ans.size();
        for(int i=0;i<ans.size()/2;i++){
            if(ans[i]!=ans[n-1-i]){
                return false;
            }
        }
        return true;
    }
};
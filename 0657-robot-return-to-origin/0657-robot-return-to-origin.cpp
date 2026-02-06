class Solution {
public:
    bool judgeCircle(string moves) {
        int n = moves.length();
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            
            char ch = moves[i];
            if(ch == 'R')
                cnt++;
            else if(ch == 'L')
                cnt--;
            else if(ch == 'U')
                cnt += 3;
            else 
                cnt -= 3;
        }

        return !cnt;
    }
};
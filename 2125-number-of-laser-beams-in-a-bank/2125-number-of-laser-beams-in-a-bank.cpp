class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0;
        int prev = 0;
        int n = bank.size();
        for(int i = 0; i < n; i++) {
            int cnt = 0;
            for(int j = 0; j < bank[i].size(); j++) {
                if(bank[i][j] == '1') cnt++;
            }
            ans += prev * cnt;
            if(cnt != 0) prev = cnt;
        }
        return ans;
    }
};
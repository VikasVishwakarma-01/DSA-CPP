class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int n = skills.size();
        int idx = -1;
        if(k >= n) {
            int ans = skills[0];
            idx = 0;
            for(int i = 1; i < n; i++) {
                if(skills[i] > ans) {
                    ans = skills[i];
                    idx = i;
                }
                
            }
            return idx;
        }
        int cnt = 0;
        idx = 0;
        int curr = skills[0];
        for(int i = 1; i < n; i++) {
            if(curr > skills[i]) {
               cnt++;
            }
            else {
                curr = skills[i];
                cnt = 1;
                idx = i;
            }

            if(cnt == k)
                return idx;
        }

        return idx;
    }
};
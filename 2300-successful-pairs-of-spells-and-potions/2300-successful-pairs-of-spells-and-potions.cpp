class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int m = potions.size();
        vector<int> ans(spells.size(), 0);
        for(int i = 0; i < spells.size(); i++) {
            int sp = spells[i];
            long long pr = (long long)potions[m-1] * sp;
            long long p1 = (long long)potions[0] * sp;
            if(pr >= success && p1 >= success) {
                ans[i] = m;
            }
            else if(pr >= success) {
                int cnt = 0;
                for(int j = m-1; j >= 0; j--) {
                    long long p = (long long)potions[j] * sp;
                    if(p >= success) cnt++;
                    else break;
                }
                ans[i] = cnt;
            }
        }

        return ans;
    }
};
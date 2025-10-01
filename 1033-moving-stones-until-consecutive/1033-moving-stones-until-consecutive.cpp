class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> pos = {a, b, c};
        sort(pos.begin(), pos.end());
        int gap1 = pos[1] - pos[0] - 1;
        int gap2 = pos[2] - pos[1] - 1;

        vector<int> ans(2);
        ans[1] = gap1 + gap2;

        if((gap1 > 1) && (gap2 > 2))
            ans[0] = 2;

        else if( (gap1 == 0 && gap2 != 0) || (gap1 != 0 && gap2 == 0) )
            ans[0] = 1;
        
        else if(gap1 == 1 || gap2 == 1)
            ans[0] = 1;

        else if(gap1 == 0 && gap2 == 0)
            ans[0] = 0;

        return ans;
    }
};
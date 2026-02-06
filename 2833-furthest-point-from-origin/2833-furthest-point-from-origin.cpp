class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.length();
        int l = 0, r = 0, under = 0;

        for(int i = 0; i < n; i++) {

            char ch = moves[i];
            if(ch == 'L')
                l++;
            else if(ch == 'R')
                r++;
            else
                under++;
        }

        return under + max(r, l) - min(r, l);

    }
};
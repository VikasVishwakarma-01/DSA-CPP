class Solution {
public:
    int minFlips(string target) {
        int n = target.size();
        int zero = 0, one = 0;

        char prev;
        int idx = 0;
        for(int i = 0; i < n; i++) {
            if(target[i] != '0') {
                prev = target[i];
                one++;
                idx = i;
                break;
            }
        }
        

        for(int i = idx + 1; i < n; i++) {
            if(target[i] != prev) {
                if(target[i] == '1')
                    one++;
                else zero++;

                prev = target[i];
            }
        }

        if(one == 0 && zero == 1)
            return 0;
            
        return zero + one;
    }
};
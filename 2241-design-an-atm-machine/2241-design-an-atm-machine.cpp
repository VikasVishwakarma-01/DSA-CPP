class ATM {
public:
    vector<int> vec = {0, 0, 0, 0, 0};
    ATM() {}
    
    void deposit(vector<int> banknotesCount) {
        
        int n = banknotesCount.size();
        for(int i = 0; i < n; i++) {
            vec[i] += banknotesCount[i];
        }
    }
    
    vector<int> withdraw(int amount) {
        vector<int> note = {20, 50, 100, 200, 500};
        int t = amount;
        vector<int> ans(5, 0);
        vector<int> v = vec;
        for(int i = 4; i >= 0; i--) {
            if(v[i] != 0 && note[i] <= t) {
                if((long long)note[i]*v[i] >= t) {
                    ans[i] = t/note[i];
                    v[i] -= t/note[i];
                    t = t % note[i];
                }
                else {
                    ans[i] = v[i];
                    t -= (long long)note[i]*v[i];
                    v[i] = 0;
                }

            }
        }
        if(t == 0) {
            vec = v;
            return ans;
        }
        return {-1};
    }
};
/*
0 20
1 50
2 100
3 200
4 500

*/




/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */
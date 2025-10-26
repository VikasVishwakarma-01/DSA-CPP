class Bank {
public:
    unordered_map<long long, long long> acc;
    Bank(vector<long long>& balance) {
        for(int i = 0; i < balance.size(); i++) {
            acc[i+1] = balance[i];
        }
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(acc.find(account1) == acc.end()) return false;
        if(acc.find(account2) == acc.end()) return false;
        if(acc[account1] >= money) {
            acc[account1] -= money;
            acc[account2] += money;
            return true;
        }
        return false;
    }
    
    bool deposit(int account, long long money) {
        if(acc.find(account) == acc.end()) return false;
        acc[account] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(acc.find(account) == acc.end()) return false;
        if(acc[account] >= money) {
            acc[account] -= money;
            return true;
        }
        return false;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
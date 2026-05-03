class Solution {
public:
    bool isPrime(int n) {
    
        if(n <= 1) 
            return false;

        for(int i = 2; i * i <= n; i++) {
            if(n % i == 0) 
                return false;
        }
        
        return true;
    }
    int sumOfPrimesInRange(int n) {
        string s = to_string(n);
        reverse(s.begin(), s.end());

        int r = stoi(s);

        int sum = 0;
        for(int i = min(n, r); i <= max(n, r); i++) {
            if(isPrime(i))
                sum += i;
        }

        return sum;
    }
};
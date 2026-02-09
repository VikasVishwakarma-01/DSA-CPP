class Solution {
public:
    int alternateDigitSum(int n) {
        vector<int> d;
        while(n) {
            d.push_back(n % 10);
            n /= 10;
        }
        reverse(d.begin(), d.end());

        int sum = 0;
        for(int i = 0; i < d.size(); i++) {
            if(i % 2 == 0)
                sum += d[i];
            else 
                sum -= d[i];
        }

        return sum;
    }
};
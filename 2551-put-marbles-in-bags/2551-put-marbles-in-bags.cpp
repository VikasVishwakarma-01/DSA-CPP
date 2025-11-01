class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        long long ans = 0;
        int n = weights.size();

        vector<long long> vec;
        for(int i = 0; i < n-1; i++) {
            vec.push_back(weights[i] + weights[i + 1]);
        }

        sort(vec.begin(), vec.end());

        long long x = 0;
        long long y = 0;
        for(int i = 0; i < k-1; i++) {
            x += vec[i];
            y += vec[vec.size() - 1 - i];
        }
        
        return y - x;
    }
};
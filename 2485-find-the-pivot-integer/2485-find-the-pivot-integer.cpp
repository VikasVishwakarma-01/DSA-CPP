class Solution {
public:
    int pivotInteger(int n) {
        if(n == 1) return 1;
        vector<int> v;
        for(int i = 1; i <= n; i++)
            v.push_back(i);

        for(int i = 1; i < n; i++)
            v[i] += v[i-1];

        for(int i = 1; i < n; i++) {
            if((v[n-1] - v[i-1]) == v[i])
                return i+1;
        }

        return -1;
    }
};
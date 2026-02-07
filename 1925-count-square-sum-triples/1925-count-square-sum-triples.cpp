class Solution {
public:
    int countTriples(int n) {
        unordered_set<int> set;
        vector<int> sq;
        for(int i = 1; i <= n; i++) {
            set.insert(i*i);
            sq.push_back(i*i);
        }

        int ans = 0;
        for(int i = 0; i < n-1; i++) {
            for(int j = i+1; j < n; j++) {
                int cnt = sq[i] + sq[j];
                if(set.find(cnt) != set.end())
                    ans++;
            }
        }

        return ans*2;
    }
};
/*

*/
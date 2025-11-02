class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = rocks.size();

        vector<int> rem;
        for(int i = 0; i < n; i++) 
            rem.push_back(capacity[i] - rocks[i]);

        sort(rem.begin(), rem.end());

        int ans = 0;
        int sum = 0;
        for(int i = 0; i < rem.size(); i++) {
            sum += rem[i];
            if(sum <= additionalRocks) 
                ans++;
            else break;
        }

        return ans;
    }
};
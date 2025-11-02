class Solution {
public:
    
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> set;

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

        for(int i = 0; i < n; i++)
            pq.push({nums[i], i});
        
        long long score = 0;
        while(pq.size() > 0) {
            auto p = pq.top();
            pq.pop();

            long long val = p.first;
            int idx = p.second;

            if(set.find(idx) == set.end()) {
                score += val;
                set.insert(idx - 1);
                set.insert(idx);
                set.insert(idx + 1);
            }
        }

        return score;
    
    }
};
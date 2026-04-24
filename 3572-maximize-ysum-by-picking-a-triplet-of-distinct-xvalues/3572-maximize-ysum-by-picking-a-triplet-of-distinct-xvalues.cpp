class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        int n = x.size();

        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; i++){
            mp[x[i]].push_back(y[i]);
        }

        priority_queue<int, vector<int>, greater<int>> pq;

        for(auto p: mp) {
            auto &v = p.second;
            sort(v.begin(), v.end());
            int val = v.back();
            pq.push(val);
            if(pq.size() > 3)
                pq.pop();
            
        }

        if(pq.size() != 3)
            return -1;
        
        int sum = 0;
        while(pq.size() > 0) {
            sum += pq.top();
            pq.pop();
        }

        return sum;
    }
};
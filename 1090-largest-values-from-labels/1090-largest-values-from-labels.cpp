class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        unordered_map<int, vector<int>> mp;

        int n = values.size();
        for(int i = 0; i < n; i++) {
            mp[labels[i]].push_back(values[i]);
        }

        priority_queue<int, vector<int>, greater<int>> pq;

        for(auto p: mp) {
            int lab = p.first;
            vector<int> &val = p.second;
            sort(val.rbegin(), val.rend());
            for(int i = 0; i < min((int)val.size(), useLimit); i++) {
                pq.push(val[i]);
                if(pq.size() > numWanted)
                    pq.pop();
            }
        }

        int sum = 0;
        while(pq.size() > 0) {
           sum += pq.top();
            pq.pop();
        }

        return sum;
    }
};
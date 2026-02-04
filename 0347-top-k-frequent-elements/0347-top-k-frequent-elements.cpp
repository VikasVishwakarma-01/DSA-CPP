class Solution {
public:
    typedef pair<int,int> pi;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mp;
        for(auto ele: nums) {
            mp[ele]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(auto pair: mp) {
            pq.push({pair.second, pair.first});
            if(pq.size() > k)
                pq.pop();
        }

        vector<int> ans;
        while(pq.size() > 0) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
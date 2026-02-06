class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        unordered_map<int, int> mp;

        for(auto x: items1) {
            int x1 = x[0];
            int x2 = x[1];

            mp[x1] = x2;
        }

        for(auto x: items2) {
            int x1 = x[0];
            int x2 = x[1];
            if(mp.find(x1) != mp.end())
                mp[x1] += x2;

            else mp[x1] = x2;
        }

        vector<vector<int>> vec;

        for(auto x: mp) {
            int key = x.first;
            int val = x.second;
            vec.push_back({key, val});
        }

        sort(vec.begin(), vec.end());
        return vec;
    }
};
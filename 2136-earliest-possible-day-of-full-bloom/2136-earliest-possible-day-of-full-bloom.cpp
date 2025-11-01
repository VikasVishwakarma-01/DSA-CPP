class Solution {
public:
    static bool cmp(pair<int,int>&a, pair<int,int>&b){
        if(a.second==b.second)
        return a.first<b.first;

        return a.second>b.second;
    } 
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int,int>> pg;
        int n = plantTime.size();

        for(int i = 0; i < n; i++) {
            pg.push_back({plantTime[i], growTime[i]});
        }
        sort(pg.begin(), pg.end(),cmp);

        
        int ans = 0;
        int maxAns = 0;
        for(int i = 0; i < n; i++) {
            int plant = pg[i].first;
            int grow = pg[i].second;
            ans += plant;
            maxAns = max(maxAns, ans + grow);
        }

        return maxAns;
    }
};
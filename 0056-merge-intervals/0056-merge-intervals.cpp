class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        auto pre = intervals[0];
        for(int i = 1; i < n; i++) {
            int x1 = pre[0];
            int y1 = pre[1];
            int x2 = intervals[i][0];
            int y2 = intervals[i][1];

            if(y1 >= x2) {
                pre[1] = max(y1, y2);
            }
            else {
                ans.push_back(pre);
                pre = intervals[i];
            }
        }

        ans.push_back(pre);

        return ans;
    }
};
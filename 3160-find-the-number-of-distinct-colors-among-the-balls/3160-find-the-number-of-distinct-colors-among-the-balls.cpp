class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> mp;
        unordered_map<int, int> no_of_colors;
        int n = queries.size();
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            int ball = queries[i][0];
            int color = queries[i][1];
            if(mp.find(ball) != mp.end()) {
                int c = mp[ball];
                no_of_colors[c]--;
                if(no_of_colors[c] == 0)
                    no_of_colors.erase(c);

                mp.erase(ball);
                mp[ball] = color;
                no_of_colors[color]++;
            }
            else {
                mp[ball] = color;
                no_of_colors[color]++;
            }

            ans.push_back(no_of_colors.size());
        }

        return ans;
    }
};
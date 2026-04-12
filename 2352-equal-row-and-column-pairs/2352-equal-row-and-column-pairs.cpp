class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        // int n = grid.size();
        // vector<string> row, col;

        // for(int i = 0; i < n; i++) {
        //     string st = "";
        //     for(int j = 0; j < n; j++) {
        //         string ch = to_string(grid[i][j]);
        //         st += ch;
        //         st += ' ';
        //     }
        //     row.push_back(st);
        // }

        // for(int i = 0; i < n; i++) {
        //     string st = "";
        //     for(int j = 0; j < n; j++) {
        //         string ch = to_string(grid[j][i]);
        //         st += ch;
        //         st += ' ';
        //     }
        //     col.push_back(st);
        // }

        // int ans = 0;
        // for(auto s1: row) {
        //     for(auto s2: col) {
        //         if(s1 == s2) 
        //             ans++;
        //     }
        // }

        // return ans;

        map<vector<int>, int> mp;
        for(auto ele: grid) {
            mp[ele]++;
        }

        int ans = 0;
        for(int i = 0; i < grid.size(); i++) {
            vector<int> col;
            for(int j = 0; j < grid.size(); j++) {
                col.push_back(grid[j][i]);
            }

            ans += mp[col];
        }

        return ans;
    }
};
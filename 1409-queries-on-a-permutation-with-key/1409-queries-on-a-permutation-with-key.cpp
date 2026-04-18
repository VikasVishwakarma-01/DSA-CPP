class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        int n = queries.size();

        vector<int> per;
        for(int i = 1; i <= m; i++)
            per.push_back(i);

        vector<int> result;
        for(int i = 0; i < n; i++) {
            int x = queries[i];

            int idx = -1;
            for(int j = 0; j < per.size(); j++) {
                if(per[j] == x) {
                    idx = j;
                    break;
                }
            }

            int y = per[idx];
            per.erase(per.begin() + idx);

            per.insert(per.begin(), y);
            result.push_back(idx);
        }

        return result;
    }
};
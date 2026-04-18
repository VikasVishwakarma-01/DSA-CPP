class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& v, vector<vector<int>>& queries) {
        int n = queries.size();

        vector<int> ans;
        for(auto q: queries) {
            int idx = q[1];
            int val = q[0];

            //vector<int> v = nums;
            v[idx] += val;

            int cnt = 0;
            for(int i = 0; i < v.size(); i++)
                if(v[i] % 2 == 0)
                    cnt += v[i];
            
            ans.push_back(cnt);
        }

        return ans;
    }
};
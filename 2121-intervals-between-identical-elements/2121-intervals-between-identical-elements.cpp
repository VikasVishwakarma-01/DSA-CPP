#define ll long long
class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        int n = arr.size();
        map<int, vector<ll>> mp;

        for(int i = 0; i < n; i++)
            mp[arr[i]].push_back(i);
         
        vector<long long> result(n,0);
        for(auto &p: mp) {
            vector<ll> idx = p.second;
            int k = idx.size();

            vector<ll> pre(k, 0);
            pre[0] = idx[0];

            for(int i = 1; i < k; i++)
                pre[i] = pre[i-1] + idx[i];

            for(int j = 0; j < k; j++) {
                ll left = 0, right = 0;

                if(j > 0)
                    left = (ll)j * idx[j] - pre[j-1];

                if(j < k-1)
                    right = pre[k-1] - pre[j] - (ll)(k - j - 1) * idx[j];
                
                result[idx[j]] = left + right;
            }
        }
        return result;
    }
};
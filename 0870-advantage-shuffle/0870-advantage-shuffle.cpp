class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();

        sort(nums1.begin(), nums1.end());
        unordered_set<int> index;
        vector<pair<int, int>> vec;
        for(int i = 0; i < n; i++) {
            vec.push_back({nums2[i], i});
            index.insert(i);
        }

        sort(vec.begin(), vec.end());

        vector<int> ans(n, -1);
        priority_queue<int> pq;
        
        int j = 0;
        for(int i = 0; i < n; i++) {
            int ele1 = nums1[i];
            int ele2 = vec[j].first;
            int idx = vec[j].second;
            if(ele1 > ele2) {
                ans[idx] = ele1;
                j++;
                index.erase(idx);
            }
            else {
                pq.push(ele1);
            }
        }

        for(auto x: index) {
            ans[x] = pq.top();
            pq.pop();
        }

        return ans;
    }
};
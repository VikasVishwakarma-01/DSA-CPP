class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> mp;

        for(auto &ch: s) {
            mp[ch]++;
        }

        priority_queue<int> pq;
        for(auto p: mp) {
            pq.push(p.second);
        }

        unordered_set<int> set;
        int ans = 0;
        while(pq.size() > 0) {
            int x = pq.top();
            if(set.find(x) == set.end())
                set.insert(x);
            else {
                x--;
                if(x != 0) 
                    pq.push(x);
                ans++;
            }
            pq.pop();
        }

        return ans;
    }
};
class Solution {
public:
    int minDeletion(string s, int k) {
        unordered_map<char,int>mp;
        priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> pq;
        for (int i = 0; i < s.length(); i++){
            mp[s[i]]++;
        }
        
        if(mp.size() <= k) return 0;

        int ans = 0;
        for(auto p: mp) {
            char ch = p.first;
            int freq = p.second;
            pq.push({freq, ch});
            if(pq.size() > k) {
                ans += pq.top().first;
                pq.pop();
            }
                
        }
        return ans;
    }
};
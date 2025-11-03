class Solution {
public:
    string customSortString(string order, string s) {
        
        int n = order.length();

        unordered_map<char,int> mp;
        for(int i = 0; i < n; i++) 
            mp[order[i]] = i;

        priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> pq;

        for(int i = 0; i < s.length(); i++) {

            char ch = s[i];
            if(mp.find(ch) != mp.end())
                pq.push({mp[ch], ch});
            else pq.push({-1, ch});
            
        }

        string ans = "";
        while(pq.size() > 0) {
            ans += pq.top().second;
            pq.pop();
        }

        return ans;
        
    }
};
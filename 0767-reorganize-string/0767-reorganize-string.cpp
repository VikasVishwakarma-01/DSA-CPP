class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();

        unordered_map<char, int> mp;

        int f = 0;
        for(auto &ch: s) {
            mp[ch]++;
            f = max(f, mp[ch]);
        }
        
        if(f > (n + 1) / 2) 
            return "";

        priority_queue<pair<int, char>> pq;
        for(auto &p: mp) {
            pq.push({p.second, p.first});
        }

        string str = "";

        while(pq.size() > 1) {
            auto [freq1, ch1] = pq.top(); pq.pop();
            auto [freq2, ch2] = pq.top(); pq.pop();

            str += ch1;
            str += ch2;

            if(--freq1 > 0) pq.push({freq1, ch1});
            if(--freq2 > 0) pq.push({freq2, ch2});
        }

        if(!pq.empty()) {
            str += pq.top().second;
        }

        return str;
    }
};
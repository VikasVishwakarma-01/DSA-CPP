class Solution {
public:
    string repeatLimitedString(string st, int repeatLimit) {
        unordered_map<char, int> mp;
        int n = st.length();

        for(auto ch: st) {
            mp[ch]++;
        }

        priority_queue<pair<char, int>> pq;

        for(auto p: mp) {
            pq.push(p);
        }

        string s = "";
        while(pq.size() > 0) {
            auto [ch1, f1] = pq.top();
            pq.pop();
            int use = min(repeatLimit, f1);
            int t = use;
            while(t--) {
                s += ch1;
            }
            
            f1 -= use;

            if(f1 > 0) {
                if(pq.size() == 0) break;

                auto [ch2, f2] = pq.top();
                pq.pop();
                s += ch2;
                f2--;
                if(f2 > 0) 
                    pq.push({ch2, f2});

                pq.push({ch1, f1});
            }
        }

        return s;
    }
};
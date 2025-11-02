class Solution {
public:
    string arrangeWords(string text) {
        string s = "";
        int n = text.size();
        priority_queue<pair<int, pair<int, string>>, vector<pair<int, pair<int, string>>>, greater<pair<int, pair<int, string>>>> pq;

        for(int i = 0; i < n; i++) {
            if(text[i] == ' ') {
                int len = s.length();
                pq.push({len, {i, s}});
                s = "";
            }
            if(text[i] != ' ') s += text[i];
        }
        int len = s.length();
        pq.push({len, {n, s}});

        string ans = "";
        while(pq.size() > 0) {
            string str = pq.top().second.second;
            pq.pop();
            ans += str;
            ans += ' ';
        }
        
        ans[0] = toupper(ans[0]);
        for(int i = 1; i < ans.size(); i++) {
            ans[i] = tolower(ans[i]);
        }
        ans.pop_back();

        return ans;
    }

};
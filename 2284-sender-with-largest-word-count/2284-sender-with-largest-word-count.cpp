class Solution {
public:
    int noOfWords(string s) {
        int n = s.length(), cnt = 0;
        for(int i = 0; i < n; i++)
            if(s[i] == ' ')
                cnt++;
            
        return cnt + 1;
            
    }
    struct cmp {
        bool operator()(pair<int, string>& a, pair<int, string>& b) {
            if (a.first == b.first)
                return a.second < b.second;
            return a.first < b.first;      
        }
    };
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        int n = messages.size();

        unordered_map<string, int> mp;
        for(int i = 0; i < n; i++) {
            string user = senders[i];
            string chat = messages[i];
            int count = noOfWords(chat);
            if(mp.find(user) == mp.end()) {
                mp[user] = count;
            }
            else {
                mp[user] += count;
            }
        }

        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> pq;
        for(auto p: mp) {
            string user = p.first;
            int count = p.second;
            
            pq.push({count, user});
        }

        return pq.top().second;
    }
};
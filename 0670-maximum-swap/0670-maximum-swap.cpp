class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        
        int n = s.length();
        priority_queue<pair<char, int>> pq;

        for(int i = 0; i < n; i++) pq.push({s[i], i});
        
        for(int i = 0; i < n; i++) {

            while(pq.top().second < i) pq.pop();

            char ch = s[i];
            char ch2 = pq.top().first;
            int j = pq.top().second;

            if(ch < ch2 && i < j) {
                swap(s[i], s[j]);
                break;
            }
        }

        int ans = stoi(s);
        return ans;
    }
};
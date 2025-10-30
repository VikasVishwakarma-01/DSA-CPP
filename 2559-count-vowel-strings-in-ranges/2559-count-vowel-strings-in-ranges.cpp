class Solution {
public:
    bool isVowel(char ch) {
        vector<char> v = {'a', 'e', 'i', 'o', 'u'};
        for(int i = 0; i < 5; i++) {
            if(ch == v[i]) return true; 
        }

        return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> pre(n);

        pre[0] = 0;
        if(isVowel(words[0][0]) && isVowel(words[0][words[0].length() - 1])) pre[0]++;
        for(int i = 1; i < n; i++) {
            int s = 0, e = words[i].length() - 1;
            pre[i] += pre[i-1];
            if(isVowel(words[i][s]) && isVowel(words[i][e])) pre[i]++;
        }

        vector<int> ans;
        for(auto q: queries) {
            int s = q[0];
            int e = q[1];
            int t = 0;
            (s > 0) ? t += (pre[e] - pre[s-1]) : t += pre[e];
            ans.push_back(t);
        }

        return ans;
    }
};
class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> v = words;
        for(int i = 0; i < words.size(); i++) {
            sort(v[i].begin(), v[i].end());
        }

        unordered_set<string> set(v.begin(), v.end());
        vector<string> ans;
        for(int i = 0; i < words.size(); i++) {
            string s = words[i];
            sort(s.begin(), s.end());
            if(set.find(s) != set.end()) {
                ans.push_back(words[i]);
                set.erase(s);
            }
        }
        if(words[0] == words[words.size() - 1]) ans.push_back(words[0]);
        return ans;
        
    }
};
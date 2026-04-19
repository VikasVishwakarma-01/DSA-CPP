class Solution {
public:
    vector<string> partitionString(string s) {
        unordered_set<string> set;
        vector<string> ans;

        string str = "";
        for(int i = 0; i < s.length(); i++) {
            str += s[i];
            if(set.find(str) == set.end()) {
                set.insert(str);
                ans.push_back(str);
                str = "";
            }
        }

        return ans;
    }
};
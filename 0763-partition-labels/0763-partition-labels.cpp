class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> mp;

        int n = s.length();
        for(int i = 0; i < n; i++)
            mp[s[i]] = i;

        vector<int> ans;
        for(int i = 0; i < n; i++) {
            char ch = s[i];
            int lastIdx = mp[ch];
            for(int j = i+1; j < lastIdx; j++){
                if(mp[s[j]] > lastIdx) 
                    lastIdx = mp[s[j]];
            }

            ans.push_back(lastIdx - i + 1);
            i = lastIdx;
        }

        return ans;
    }
};
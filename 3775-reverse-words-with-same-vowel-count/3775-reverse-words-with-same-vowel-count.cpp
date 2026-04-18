class Solution {
public:
    string reverseWords(string s) {
        vector<string> vec;
        int n = s.length();

        unordered_map<string, int> mp;

        string str = "";
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                cnt++;
            }
            if(s[i] == ' ') {
                vec.push_back(str);
                mp[str] = cnt;
                cnt = 0;
                str = "";
            }
            else {
                str += s[i];
            }
        }

        vec.push_back(str);
        mp[str] = cnt;


        int x = mp[vec[0]];
        string ans = "";
        ans += vec[0];
        ans += ' ';
        for(int i = 1; i < vec.size(); i++) {
            string st = vec[i];
            if(mp[vec[i]] == x) {
                reverse(st.begin(), st.end());
            }

            ans += st;
            if(i != vec.size() - 1) ans += ' ';
        }
        if(ans.back() == ' ')
            ans.pop_back();
            
        return ans;
    }
};
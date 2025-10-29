class Solution {
public:
    bool isVowel(char ch) {
        vector<char> v = {'a', 'e', 'i', 'o', 'u'};
        for(int i = 0; i < 5; i++) {
            if(ch == v[i]) return true;
        }

        return false;
    }
    int vowelStrings(vector<string>& words, int left, int right) {
        int n = words.size();
        int cnt = 0;
        for(int k = left; k <= right; k++) {
            int i = 0;
            int j = words[k].size()-1;
            if (isVowel(words[k][i]) && isVowel(words[k][j])) {
                cnt++;
            }
        }

        return cnt;
    }
};
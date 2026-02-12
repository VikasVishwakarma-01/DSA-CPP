class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        if(haystack == needle) return 0;
        if(haystack.length() < needle.length()) return -1;
        for(int i = 0; i < n-needle.size()+1; i++) {
            if(haystack[i] == needle[0]) {
                string str = "";
                for(int j = i; j < i+needle.size(); j++) {
                    str += haystack[j];
                }
                if(str == needle) return i;
            }
        }

        return -1;
    }
};
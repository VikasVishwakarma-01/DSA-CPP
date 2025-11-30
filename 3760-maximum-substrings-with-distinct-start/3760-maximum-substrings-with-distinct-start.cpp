class Solution {
public:
    int maxDistinct(string s) {
        unordered_set<char> set(s.begin(), s.end());
        return set.size();
    }
};
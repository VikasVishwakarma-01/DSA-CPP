class Solution {
public:
    bool consecutiveSetBits(int n) {
        string s = bitset<32>(n).to_string();

        int pairs = 0;

        for (int i = 0; i < 31; i++) {
            if (s[i] == '1' && s[i + 1] == '1')
                pairs++;
        }

        return pairs == 1;
    }
};
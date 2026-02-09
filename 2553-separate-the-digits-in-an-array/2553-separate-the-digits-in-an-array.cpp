class Solution {
public:
    
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(auto &n: nums) {
            vector<int> d;
            while(n > 0) {
                d.push_back(n % 10);
                n /= 10;
            }

            reverse(d.begin(), d.end());
            
            for(auto x: d) {
                ans.push_back(x);
            }
        }

        return ans;
    }
};
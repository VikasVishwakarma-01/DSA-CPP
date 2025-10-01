class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        
        int p = 1;
        while(true) {
            if(set.find(p) == set.end()) {
                return p;
            } 
            p *= 2;
        }

        return 0;
    }
};
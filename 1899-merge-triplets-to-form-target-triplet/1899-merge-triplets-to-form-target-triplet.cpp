class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int x = 0, y = 0, z = 0;

        for(auto &t : triplets) {
            if(t[0] > target[0] || t[1] > target[1] || t[2] > target[2])
                continue;
            if(t[0] == target[0]) x = 1;
            if(t[1] == target[1]) y = 1;
            if(t[2] == target[2]) z = 1;
        }

        return x && y && z;
    }
};
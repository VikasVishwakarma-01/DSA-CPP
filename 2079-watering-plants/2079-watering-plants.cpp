class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int n = plants.size();
        
        int cnt = 0;
        int steps = 0;
        for(int i = 0; i < n; i++) {
            if(cnt < plants[i]) {
                cnt = capacity;
                steps += i*2 + 1;
                cnt -= plants[i];
            }
            else {
                steps++;
                cnt -= plants[i];
            }
        }

        return steps;
    }
};
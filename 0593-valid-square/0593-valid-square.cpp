class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<int> dist;

        vector<vector<int>> p = {p1, p2, p3, p4};

        for(int i = 0; i < 3; i++) {
            for(int j = i + 1; j < 4; j++) {
                int x1 = p[i][0], y1 = p[i][1], x2 = p[j][0], y2 = p[j][1];
                int x = abs(x1 - x2);
                int y = abs(y1 - y2);
                dist.push_back(x * x + y * y);
                cout << x * x + y * y<< " "; 
            }
        }

        sort(dist.begin(), dist.end());
        
        for(int i = 1; i < 4; i++) {
            if(dist[i] != dist[i - 1]) return false;
        }

        if(dist[4] != dist[5]) return false;

        return true;
    }
};
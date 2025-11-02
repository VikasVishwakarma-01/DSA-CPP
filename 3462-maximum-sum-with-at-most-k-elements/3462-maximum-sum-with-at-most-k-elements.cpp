class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        int n = grid.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < n; i++) {
            priority_queue<int, vector<int>, greater<int>> q;
            int l = limits[i];
            for(int j = 0; j < grid[i].size(); j++) {
                q.push(grid[i][j]);
                if(q.size() > l)
                    q.pop();
            }
            while(q.size() > 0) {
                pq.push(q.top());
                q.pop();
            }
        }

        while(pq.size() > k)
            pq.pop();
        
        long long ans = 0;
        while(pq.size() > 0) {
            ans += pq.top();
            pq.pop();
        }
        
        return ans;
    }
};
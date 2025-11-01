class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int n = piles.size();
        priority_queue<int> pq;

        for(int i = 0; i < n; i++) 
            pq.push(piles[i]);
        
        while(k--) {
            int top = pq.top();
            pq.pop();

            top -= top/2;
            pq.push(top); 
        }

        int total = 0;
        while(pq.size() > 0) {
            total += pq.top();
            pq.pop();
        }

        return total;
    }
};
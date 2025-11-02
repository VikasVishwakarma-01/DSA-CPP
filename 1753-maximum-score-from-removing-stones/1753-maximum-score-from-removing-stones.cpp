class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int> pq;
        pq.push(a);
        pq.push(b);
        pq.push(c);

        int ans = 0;
        while(pq.size() > 1) {
            int t = pq.top();
            pq.pop();
            t--;
            if(pq.size() > 0) {
                int y = pq.top();
                pq.pop();
                y--;
                ans++;
                if(y > 0)
                    pq.push(y);
                if(t > 0)
                    pq.push(t);
            }
        }

        return ans;
    }
};
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i = 0; i < n; i++)
            pq.push(nums[i]);

        int op = 0;
        while(pq.size() >= 2 && pq.top() < k) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            
            int x = (min(a, b) * 2 + max(a, b));
            pq.push(x);
            op++;
        }

        return op;
    }
};
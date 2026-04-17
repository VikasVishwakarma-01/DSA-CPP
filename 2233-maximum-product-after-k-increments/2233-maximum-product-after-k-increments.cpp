class Solution {
public:
    const int mod = 1000000007;
    int maximumProduct(vector<int>& nums, int k) {
        int n = nums.size();

        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i = 0; i < n; i++) {
            pq.push(nums[i]);
        }

        while(k > 0) {
            int x = pq.top();
            pq.pop();
            x++;
            pq.push(x);
            k--;
        }

        int ans = 1;

        while(pq.size() > 0) {
            ans = (1LL * ans * pq.top()) % mod;
            pq.pop();
        }

        return ans % mod;
    }
};
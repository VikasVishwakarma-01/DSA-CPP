class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int curr = arr[0];
        int cnt = 0;

        int n = arr.size();
        for(int i = 1; i < n; i++) {
            if(curr > arr[i]) {
                cnt++;
            }

            else {
                curr = arr[i];
                cnt = 1;
            }

            if(cnt == k)
                return curr;
        }

        return curr;
    }
};
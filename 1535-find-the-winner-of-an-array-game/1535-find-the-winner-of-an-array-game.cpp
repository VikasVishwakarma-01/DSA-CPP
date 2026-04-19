class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int pre = -1;
        int cnt = 0;
        int n = arr.size();
        for(int i = 0; i < n; i++) {
            int x = arr[0];
            int y = arr[1];
            if(x > y) {
                if(pre != x) {
                    pre = x;
                    cnt = 1;
                }
                else cnt++;

                if(cnt == k)
                    return x;
                arr.erase(arr.begin() + 1);
                arr.push_back(y);
            }
            else {
                if(pre != y) {
                    pre = y;
                    cnt = 1;
                }
                else cnt++;
                
                if(cnt == k)
                    return y;
                arr.erase(arr.begin() + 0);
                arr.push_back(x);

            }
        }

        return pre;
    }
};
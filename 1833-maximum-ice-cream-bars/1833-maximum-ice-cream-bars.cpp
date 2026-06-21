class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int ans = 0;
        if(costs[0]>coins){
            return 0;
        }
        for(int i=0;i<costs.size();i++){
            if(coins>=costs[i]){
                coins -= costs[i];
                ans++;
            }
            else{
                break;
            }
        }
        return ans;
    }
};
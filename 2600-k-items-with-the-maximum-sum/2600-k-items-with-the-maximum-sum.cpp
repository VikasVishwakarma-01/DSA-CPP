class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int ans = 0;
        if(k <= numOnes) return k;
        ans += numOnes;
        k -= numOnes;
        if(k <= numZeros) return ans;
        k -= numZeros;
        return ans - k * 1;
    }
};
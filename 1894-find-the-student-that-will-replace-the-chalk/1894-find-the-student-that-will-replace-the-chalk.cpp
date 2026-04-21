class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = 0;
        int n = chalk.size();

        for(int i = 0; i < n; i++) {
            sum += chalk[i];
        }

        if(sum < k) {
            k = k % sum;
        }
        cout<<sum;
        for(int i = 0; i < n; i++) {
            
            if(chalk[i] <= k)
                k -= chalk[i];
            else 
                return i;
        }

        return 0;
    }
};
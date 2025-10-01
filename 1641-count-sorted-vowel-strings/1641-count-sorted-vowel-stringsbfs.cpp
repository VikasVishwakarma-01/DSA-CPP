class Solution {
public:
    int countVowelStrings(int n) {
        if(n == 1) return 5;
        vector<int> v = {5, 4, 3, 2, 1};
        
        for(int i = 0; i < n-2; i++) {
            int sum = 0;
            for(int k = 0; k < 5; k++) sum += v[k];
            vector<int> temp(5);
            temp[0] = sum;
            for(int j = 1; j < 5; j++) {
                temp[j] = temp[j-1] - v[j-1];
            }
            v = temp;
        }

        int sum = 0;
        for(int i = 0; i < v.size(); i++) {
            sum += v[i];
        }

        return sum;

    }
};
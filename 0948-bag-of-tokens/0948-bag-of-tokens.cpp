class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());

        int n = tokens.size();
        int i = 0, j = n-1;
        int score = 0, maxScore = 0;
        while(i <= j) {
            if(power >= tokens[i]) {
                score++;
                power -= tokens[i];
                maxScore = max(maxScore, score);
                i++;
            }
            else if(score > 0) {
                power += tokens[j];
                score--;
                j--;
            }
            else break;
        }
        return maxScore;
    }
};
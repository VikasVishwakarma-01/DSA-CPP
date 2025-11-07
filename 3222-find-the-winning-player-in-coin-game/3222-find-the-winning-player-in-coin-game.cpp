class Solution {
public:
    string winningPlayer(int x, int y) {
        int ans = 0;

        while(x >= 1 && y >= 4) {
            ans++;
            x--;
            y -= 4;
        }

        if(ans % 2 == 0)
            return "Bob";

        return "Alice";
    }
};
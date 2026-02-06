class Solution {
public:
    string interpret(string command) {
        string ans = "";
        int n = command.length();
        for(int i = 0; i < n; i++) {
            char ch = command[i];
            if(ch == 'G') 
                ans += ch;
            
            else if(ch == '(') {
                if(command[i+1] == ')')
                    ans += 'o';

                else
                    ans += "al";
            }

            else {
                continue;
            }
        }

        return ans;
    }
};
class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()) return false;
        for(int i = 0; i < goal.length(); i++){
            string fro = "";
            fro += goal.substr(0, goal.length()-1);
            string bac;
            bac = goal[goal.length()-1];
            bac += fro;
            if(bac == s) return true;
            
            goal = bac;
        }
        return false;
    }
        
};
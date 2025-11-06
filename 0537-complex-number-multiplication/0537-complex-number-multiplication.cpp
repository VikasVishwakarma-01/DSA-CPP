class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        string st = "";
        int idx = 0;
        for(int i = 0; i < num1.size(); i++) {
            if(num1[i] != '+')
                st += num1[i];
            else {
                idx = i;
                break;
            }
        }

        int a = stoi(st);
        st = "";

        for(int i = idx + 1; i < num1.size(); i++) {
            if(num1[i] != 'i')
                st += num1[i];
            else break;
        }

        int b = stoi(st);

        st = "";
        idx = 0;

        for(int i = 0; i < num2.size(); i++) {
            if(num2[i] != '+')
                st += num2[i];
            else {
                idx = i;
                break;
            }
        }

        int c = stoi(st);
        st = "";

        for(int i = idx + 1; i < num2.size(); i++) {
            if(num2[i] != 'i')
                st += num2[i];
            else break;
        }

        int d = stoi(st);

        st = "";
        string x = to_string(a*c - b*d);
        string y = to_string(a*d + c*b);

        st = x + '+' +  y + 'i';

        return st;

    }
};

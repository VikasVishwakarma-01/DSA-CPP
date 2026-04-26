class Solution {
public:
    int nextGreaterElement(int n) {
        // if(n>=1 && n<=11) return -1;
        // if(n<100){
        //     string s = to_string(n);
        //     reverse(s.begin(), s.end());
        //     int num = stoi(s);
        //     if(num>n) return num;
        //     else return -1;
        // }
        // string s = to_string(n);
        // int num = stoi(s);
        // for(int i=s.length()-1;i>=1;i--){
        //     sort(s.begin() + i, s.end());
        //     num = stoi(s);
        //     if(num>n && num<=INT_MAX) return num;
        // }
        // sort(s.begin(), s.end());
        // reverse(s.begin(), s.end());
        // num = stoi(s);
        // if(num>n && num<=INT_MAX) return num;
        // return -1;

        priority_queue<string, vector<string>, greater<string>> pq;
        string s = to_string(n);
        sort(s.begin(), s.end());
        pq.push(s);
        while(next_permutation(s.begin(), s.end())) pq.push(s);

        while(pq.size() > 0) {
            string str = pq.top();
            pq.pop();
            if(str == to_string(n))
                break;
        }
        
        if(pq.size() > 0) {
            long long ans = stoll(pq.top());
            if(ans > INT_MAX)
                return -1;
            
            int result = ans;
            return result;
        }

        return -1;
    }
};
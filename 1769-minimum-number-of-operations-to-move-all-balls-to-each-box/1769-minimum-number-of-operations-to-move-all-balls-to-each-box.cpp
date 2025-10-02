class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans;
        int n = boxes.size();
        for(int i = 0; i < n; i++) {
            int val = 0;
            for(int j = 0; j < n; j++)
                if(i != j) 
                    if(boxes[j] == '1') 
                        val += abs(i-j);
            ans.push_back(val);
        }

        return ans;
    }
};
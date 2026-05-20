class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ans;
        unordered_map<int, int> mp1;
        unordered_map<int,int> mp2;
        for(int i = 0; i < n; i++) {
            mp1[A[i]]++;
            mp2[B[i]]++;
            int com = 0;
            for(auto x: mp1){
                if(mp2.find(x.first)!=mp2.end()){
                    com++;
                }
            }
            ans.push_back(com);
            com = 0;
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> set1;
        vector<int> ans;
        for(int i=0;i<n;i++){
            set1.insert(nums[i]);
        }
        for(int i=1;i<=n;i++){
            if(set1.find(i)==set1.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
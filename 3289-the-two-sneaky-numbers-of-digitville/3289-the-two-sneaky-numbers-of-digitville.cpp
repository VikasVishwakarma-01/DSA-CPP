class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        vector<int>ans;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            if(mp[nums[i]]==2){
                ans.push_back(nums[i]);;
            }
        }
        for(int i=0;i<n;i++){
            if(mp.find(nums[i])!=mp.end()){
                mp[nums[i]]--;
                if(mp[nums[i]]==0){
                    mp.erase(nums[i]);
                }
            }
        }
        return ans;
    }
};
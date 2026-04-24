class Solution {
public:
    int maxScore(vector<int>& nums) {
        int n = nums.size();

        vector<long long> pos, neg, zero;
        for(int i = 0; i < n; i++) {

            if(nums[i] < 0)
                neg.push_back(nums[i]);

            else if(nums[i] > 0)
                pos.push_back(nums[i]);

            else zero.push_back(0);

        }

        if(pos.empty()) return 0;
        if(neg.empty()) return n;

        for(int i = 1; i < pos.size(); i++) {
            pos[i] += pos[i-1];
        }
        
        sort(neg.rbegin(), neg.rend());

        bool flag = true;
        for(int i = 0; i < neg.size(); i++) {
            long long ele = neg[i];
            long long last = pos.back();
            if(last + ele <= 0 && flag) {
                for(int j = 0; j < zero.size(); j++)
                    pos.push_back(last);
                flag = false;
            }
            pos.push_back(last + ele);
        }

        int ans = 0;
        for(int i = 0; i < pos.size(); i++) {
            if(pos[i] > 0)
                ans++;
        }
        if(flag)
            ans += zero.size();

        return ans;
    }
};
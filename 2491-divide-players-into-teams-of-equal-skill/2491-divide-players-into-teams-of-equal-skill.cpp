class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();

        sort(skill.begin(), skill.end());
        
        long long ans = 0;
        for(int i = 0; i < n/2; i++) {
            if(skill[n-1] + skill[0] == skill[i] + skill[n-i-1]) ans += 1LL * skill[i] * skill[n-1-i];
            else return -1;
        }

        return ans;
    }
};

 

class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        int n = tasks.size();
        sort(tasks.begin(), tasks.end());
        sort(processorTime.begin(), processorTime.end());
        int j = processorTime.size()-1;
        int ans = 0;
        for(int i = 0; i < n; i+=4) {
            int t1 = tasks[i], t2 = tasks[i+1], t3 = tasks[i+2], t4 = tasks[i+3];
            int pt = processorTime[j];
            ans = max({ans, t1+pt, t2+pt, t3+pt, t4+pt});
            j--;
        }

        return ans;
    }
};
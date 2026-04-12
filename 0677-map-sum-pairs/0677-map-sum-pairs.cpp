class MapSum {
public:
    unordered_map<string, int> mp;
    MapSum() {}
    
    void insert(string key, int val) {
        mp[key] = val;
    }
    
    int sum(string prefix) {
        int ans = 0;
        for(auto p: mp) {
            string key = p.first;
            int val = p.second;
            bool flag = true;

            for(int i = 0; i < prefix.size(); i++) {
                char ch1 = prefix[i];
                char ch2 = key[i];
                if(ch1 != ch2) {
                    flag = false;
                    break;
                }

            }

            if(flag)
                ans += val;
        }

        return ans;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
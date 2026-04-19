class RandomizedCollection {
public:
    unordered_map<int, int> mp;
    vector<int> v;
    RandomizedCollection() {}
    
    bool insert(int val) {
        v.push_back(val);
        if(mp.find(val) == mp.end()) {
            mp[val]++;
            return true;
        }
        else mp[val]++;
        return false;
    }
    
    bool remove(int val) {
        if(mp.find(val) != mp.end()) {
            mp[val]--;
            auto it = find(v.begin(), v.end(), val);
            if(it != v.end()) {
                v.erase(it);
            }
            if(mp[val] == 0)
                mp.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int idx = rand() % v.size();
        return v[idx];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
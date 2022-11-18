class RandomizedSet {
    unordered_map<int, int> mp;
    vector<int> v;
public:
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if (mp.count(val)) return false;
        mp[val] = v.size();
        v.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (mp.count(val) == 0) return false;
        v[mp[val]] = v.back();
        mp[v.back()] = mp[val];
        v.pop_back();
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        return v[rand() % v.size()];
    }
};

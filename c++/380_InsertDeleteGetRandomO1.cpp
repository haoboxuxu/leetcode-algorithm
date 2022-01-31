class RandomizedSet {
public:
    unordered_map<int, int> mp;
    vector<int> nums;
    
    RandomizedSet() {}
    
    bool insert(int val) {
        if (mp.count(val) == 0) {
            nums.push_back(val);
            mp[val] = nums.size() - 1;
            return true;
        }
        return false;
    }
    
    bool remove(int x) {
        if (mp.count(x) == 0) return false;
        int y = nums.back();
        int px = mp[x], py = mp[y];
        swap(nums[px], nums[py]), swap(mp[x], mp[y]);
        nums.pop_back(), mp.erase(x);
        return true;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (auto n : nums) {
            if (s.count(n)) {
                return true;
            }
            s.insert(n);
        }
        return false;
    }
};

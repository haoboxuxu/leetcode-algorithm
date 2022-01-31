class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        typedef long long LL;
        multiset<LL> s;
        s.insert(1e18), s.insert(-1e18);
        for (int i = 0, j = 0; i < nums.size(); i++) {
            if (i - j > k) s.erase(s.find(nums[j++]));
            int x = nums[i];
            auto it = s.lower_bound(x);
            if (*it - x <= t) return true;
            --it;
            if (x - *it <= t) return true;
            s.insert(x);
        }
        return false;
    }
};

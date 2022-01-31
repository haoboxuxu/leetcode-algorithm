class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for (auto num : nums) s.insert(num);
        int res = 0;
        for (auto x : nums) {
            if (s.count(x) && !s.count(x - 1)) {
                s.erase(x);
                int y = x;
                while (s.count(y+1)) {
                    y++;
                    s.erase(y);
                }
                res = max(res, y - x + 1);
            }
        }
        return res;
    }
};
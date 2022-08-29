class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (auto x : nums) mp[x]++;
        int n = nums.size();
        vector<int> vec(n + 1);
        for (auto [key, val] : mp) {
            vec[val]++;
        }
        int i = n, t = 0;
        while (t < k) t += vec[i--];
        vector<int> res;
        for (auto [key, val] : mp) {
            if (val > i) res.push_back(key);
        }
        return res;
    }
};
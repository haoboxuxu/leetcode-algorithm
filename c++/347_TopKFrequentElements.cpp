class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (auto num : nums) mp[num]++;
        int n = nums.size();
        vector<int> vec(n + 1);
        for (auto [k, v] : mp) {
            vec[v]++;
        }
        int i = n, t = 0;
        while (t < k) t += vec[i--];
        vector<int> res;
        for (auto [k, v] : mp) {
            if (v > i) res.push_back(k);
        }
        return res;
    }
};
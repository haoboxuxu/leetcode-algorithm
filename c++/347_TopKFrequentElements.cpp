class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (auto num : nums) mp[num]++;
        int n = nums.size();
        vector<int> v(n+1);
        
        for (auto [num, cnt] : mp) v[cnt]++;
        int i = n, t = 0;
        while (t < k) {
            t += v[i--];
        }
        vector<int> res;
        for (auto [num, cnt] : mp) {
            if (cnt > i) res.push_back(num);
        }
        return res;
    }
};

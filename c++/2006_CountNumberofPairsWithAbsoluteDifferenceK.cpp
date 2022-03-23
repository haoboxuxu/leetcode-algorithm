class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (mp.count(nums[i] - k)) res += mp[nums[i] - k];
            if (mp.count(nums[i] + k)) res += mp[nums[i] + k];
            mp[nums[i]]++;
        }
        return res;
    }
};

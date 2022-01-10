class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            int r = target - nums[i];
            if (mp.count(r)) return {mp[r], i};
            mp[nums[i]] = i;
        }
        return {};
    }
};

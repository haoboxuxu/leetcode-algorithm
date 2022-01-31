class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int k = 0;
        while (k < nums.size() && nums[k] == 0) k++;
        for (int i = k + 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) return false;
        }
        return (nums[nums.size() - 1] - nums[k]) <= 4;
    }
};

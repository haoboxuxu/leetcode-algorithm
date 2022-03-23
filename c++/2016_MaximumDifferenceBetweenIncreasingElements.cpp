class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int a = nums[0];
        int res = -1;
        for (int i = 1; i < nums.size(); i++) {
            a = min(a, nums[i]);
            if (nums[i] > a) res = max(res, nums[i] - a);
            else a = nums[i];
        }
        return res;
    }
};

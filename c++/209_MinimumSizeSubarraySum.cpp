class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = INT_MAX;
        for (int i = 0, j = 0, sum = 0; j < nums.size(); j++) {
            sum += nums[j];
            while (sum - nums[i] >= target) sum -= nums[i++];
            if (sum >= target) {
                res = min(res, j - i + 1);
            }
        }
        if (res == INT_MAX) res = 0;
        return res;
    }
};
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = INT_MAX;
        for (int i = 0, j = 0, sum = 0; i < nums.size(); i++) {
            sum += nums[i];
            while (sum - nums[j] >= target) {
                sum -= nums[j];
                j++;
            }
            if (sum >= target) {
                res = min(res, i-j+1);
            }
        }
        if (res == INT_MAX) res = 0;
        return res;
    }
};

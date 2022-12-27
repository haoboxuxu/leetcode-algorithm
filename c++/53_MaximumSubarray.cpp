class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n);
        f[0] = nums[0];
        int res = f[0];
        for (int i = 1; i < n; i++) {
            f[i] = max(f[i - 1] + nums[i], nums[i]);
            res = max(res, f[i]);
        }
        return res;
    }
};
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(2);
        f[0 & 1] = nums[0];
        int res = f[0 & 1];
        for (int i = 1; i < n; i++) {
            f[i & 1] = max(f[i - 1 & 1] + nums[i], nums[i]);
            res = max(res, f[i & 1]);
        }
        return res;
    }
};
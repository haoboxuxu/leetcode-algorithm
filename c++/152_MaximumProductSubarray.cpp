class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(2), g(2);
        f[0 & 1] = g[0 & 1] = nums[0];
        int res = f[0];
        for (int i = 1; i < n; i++) {
            f[i & 1] = max(f[i - 1 & 1] * nums[i], max(g[i - 1 & 1] * nums[i], nums[i]));
            g[i & 1] = min(g[i - 1 & 1] * nums[i], min(f[i - 1 & 1] * nums[i], nums[i]));
            res = max(res, f[i & 1]);
        }
        return res;
    }
};
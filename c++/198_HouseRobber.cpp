class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(2), g(2);
        for (int i = 1; i <= n; i++) {
            f[i & 1] = g[i - 1 & 1] + nums[i - 1];
            g[i & 1] = max(g[i - 1 & 1], f[i - 1 & 1]);
        }
        return max(g[n & 1], f[n & 1]);
    }
};
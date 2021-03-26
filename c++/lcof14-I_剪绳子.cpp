// dp
class Solution {
public:
    int cuttingRope(int n) {
        vector<int> dp;
        dp.resize(n+1);
        dp[2] = 1;
        // rope len
        for (int i = 3; i <= n; i++) {
            // cut len
            for (int j = 0; j < i; j++) {
                dp[i] = max(dp[i], max(j * (i - j), j * dp[i-j]));
            }
        }
        return dp[n];
    }
};
// math 这是tm人想出来的
class Solution {
public:
    int cuttingRope(int n) {
        if (n <= 3) return n-1;
        int a = n/3, b = n %3;
        if (b == 0) return pow(3, a);
        if (b == 1) return pow(3, a-1) * 4;
        return pow(3, a) * 2;
    }
};

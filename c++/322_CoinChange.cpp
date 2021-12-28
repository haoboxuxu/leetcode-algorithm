class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, 1e8);
        dp[0] = 0;
        for (int coin : coins) {
            for (int j = coin; j <= amount; j++) {
                dp[j] = min(dp[j], dp[j-coin] + 1);
            }
        }
        if (dp[amount] == 1e8) return -1;
        else return dp[amount];
    }
};

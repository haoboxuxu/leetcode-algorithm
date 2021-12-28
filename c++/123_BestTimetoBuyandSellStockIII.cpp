class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> f(n+2);
        for (int i = 1, min_price = INT_MAX; i <= n; i++) {
            f[i] = max(f[i-1], prices[i-1] - min_price);
            min_price = min(prices[i-1], min_price);
        }
        int res = 0;
        for (int i = n, max_profit = 0; i; i--) {
            res = max(res, max_profit - prices[i - 1] + f[i - 1]);
            max_profit = max(max_profit, prices[i - 1]);
        }
        return res;
    }
};

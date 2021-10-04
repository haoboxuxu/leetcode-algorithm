class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int INF = 1e9;
        int min_price = INF, max_profit = 0;
        for (int p : prices) {
            max_profit = max(max_profit, p - min_price);
            min_price = min(min_price, p);
        }
        return max_profit;
    }
};

class Solution {
    public int maxProfit(int[] prices) {
        //dp[i] = max(dp[i-1], prices[i] - min(prices[0 : i]))
        int profit = 0;
        int cost = Integer.MAX_VALUE;
        for (int price : prices) {
            cost = Math.min(cost, price);
            profit = Math.max(profit, price - cost);
        }
        return profit;
    }
}

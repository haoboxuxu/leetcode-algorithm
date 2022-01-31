class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = 1e6, res = 0;
        for (auto p : prices) {
            min_price = min(min_price, p);
            res = max(res, p - min_price);
        }
        return res;
    }
};
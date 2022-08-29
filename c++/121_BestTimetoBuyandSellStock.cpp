class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX, res = 0;
        for (auto p : prices) {
            min_price = min(min_price, p);
            res = max(res, p - min_price);
        }
        return res;
    }
};
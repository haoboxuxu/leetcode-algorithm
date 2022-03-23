class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int res = 0, maxLen = 0;
        for (auto& r : rectangles) {
            int l = r[0], w = r[1];
            int k = min(l, w);
            if (k == maxLen) res++;
            else if (k > maxLen) maxLen = k, res = 1;
        }
        return res;
    }
};

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int res = 0;
        long p = 1;
        for (int i = columnTitle.size() - 1; i >= 0; i--) {
            int c = columnTitle[i] - 'A' + 1;
            res += c * p;
            p *= 26;
        }
        return res;
    }
};

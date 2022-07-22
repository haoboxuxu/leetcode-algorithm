class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        n = min(n, 10);
        if (!n) return 1;
        vector<int> f(n + 1);
        f[1] = 9;
        for (int i = 2; i <= n; i++) {
            f[i] = f[i - 1] * (11 - i);
        }
        int res = 1;
        for (int i = 1; i <= n; i++) {
            res += f[i];
        }
        return res;
    }
};

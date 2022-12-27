class Solution {
public:
    double myPow(double x, int _n) {
        typedef long long LL;
        LL n = abs(_n);
        bool flag = _n > 0;
        double res = 1;
        while (n) {
            if (n & 1) res *= x;
            n >>= 1;
            x *= x;
        }
        return flag ? res : 1.0 / res;
    }
};
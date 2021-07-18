// sol1
class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x, res = -1;
        
        while (l <= r) {
            int mid = l + (r-l) / 2;
            if ((long long)mid * mid <= x) {
                l += 1;
                res = mid;
            } else {
                r = mid - 1;
            }
        }
        
        return res;
    }
};
// sol2
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }
        
        int res = exp(0.5 * log(x));
        return (long long)(res+1)*(res+1) <= x ? res+1 : res;
    }
};
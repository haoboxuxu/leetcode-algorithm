class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x, res = -1;
        
        while (l <= r) {
            long mid = l + (r - l) / 2;
            if (mid*mid <= x) {
                res = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        
        return res;
    }
};

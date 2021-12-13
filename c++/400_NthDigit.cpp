class Solution {
public:
    int findNthDigit(int n) {
        long long k = 1, t = 9, res = 1;
        while (n > k * t) {
            n -= k * t;
            k += 1;
            t *= 10;
            res *= 10;
        }
        res += (n + k - 1) / k - 1;
        n = n % k ? n % k : k;
        return to_string(res)[n-1] - '0';
    }
};

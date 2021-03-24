class Solution {
public:
    int fib(int n) {
        int mod = (int)1e9+7;
        int a = 0, b = 1;
        while (n--) {
            int c = a + b;
            a = b % mod;
            b = c % mod;
        }
        return a % mod;
    }
};

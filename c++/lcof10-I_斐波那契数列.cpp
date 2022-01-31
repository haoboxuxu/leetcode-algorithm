class Solution {
public:
    int fib(int n) {
        int a = 0, b = 1;
        int mod = 1e9+7;
        for (int i = 0; i < n; i++) {
            int c = a + b;
            a = b % mod, b = c % mod;
        }
        return a % mod;
    }
};
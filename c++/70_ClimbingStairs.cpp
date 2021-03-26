class Solution {
public:
    int numWays(int n) {
        if (n <= 2) return n;
        int a = 0, b = 0, c = 1;
        for (int i = 1; i <= n; i++){
            a = b;
            b = c;
            c = a + b;
        }
        return c;
    }
};

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        if(dividend == INT_MIN && divisor == 1) return INT_MIN;
        
        bool flag = (dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0);
        
        int res = 0;
        long num1 = abs(dividend);
        long num2 = abs(divisor);
        
        while (num2 <= num1) {
            int shift = 0;
            while (num1 >= (num2 << shift)) {
                shift += 1;
            }
            num1 -= (num2 << (shift-1));
            res += (1 << (shift-1));
        }
        
        return flag ? res : -res;
    }
};

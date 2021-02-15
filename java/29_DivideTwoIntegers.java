class Solution {
    public int divide(int dividend, int divisor) {
        if(dividend == Integer.MIN_VALUE && divisor == -1) return Integer.MAX_VALUE;
        if(dividend == Integer.MIN_VALUE && divisor == 1) return Integer.MIN_VALUE;

        boolean flag = (dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0);
        long res = 0;
        long num1 = Math.abs((long)dividend), num2 = Math.abs((long)divisor);

        while (num2 <= num1) {
            int shift = 0;
            while (num1 >= (num2 << shift)) {
                shift += 1;
            }
            num1 -= num2 << (shift - 1);
            res += 1 << (shift - 1);
        }

        return flag ? (int) res : (int) -res;
    }
}

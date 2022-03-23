class Solution {
public:
    int getSum(int a, int b) {
        while (b) {
            int sum = a ^ b;
            int carry = (unsigned int)(a & b) << 1;
            a = sum, b = carry;
        }
        return a;
    }
};
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = 1;
        for (int i = n - 1; i >= 0; i--) {
            carry += digits[i];
            digits[i] = carry % 10;
            carry /= 10;
        }

        if (carry) {
            digits[0] %= 10;
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};
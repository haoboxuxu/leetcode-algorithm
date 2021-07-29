class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = (int)digits.size();
        digits[len-1] += 1;
        
        int carry = 0;
        
        for (int i = len-1; i > 0; i--) {
            digits[i] += carry;
            carry = digits[i] / 10;
            digits[i] %= 10;
        }
        
        digits[0] += carry;
        if (digits[0] >= 10) {
            digits[0] %= 10;
            digits.insert(digits.begin(), 1);
        }
        
        return digits;
    }
};

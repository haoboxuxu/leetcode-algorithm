class Solution {
public:
    int translateNum(int num) {
        if (num < 9) return 1;
        if (num % 100 >= 10 && num % 100 <= 25) {
            return translateNum(num / 10) + translateNum(num / 100);
        } else {
            return translateNum(num / 10);
        }
    }
};
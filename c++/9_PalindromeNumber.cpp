class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return 0;
        long long rx = 0;
        int t = x;
        while (t) {
            rx = rx * 10 + t % 10;
            t /= 10;
        }
        return rx == x;
    }
};

class Solution {
public:
    int myAtoi(string s) {
        if (s.length() == 0) return 0;
        int res = 0;
        bool flag = true;
        
        int i = 0;
        while (s[i] == ' ' && (i+1) < s.length()) {
            i++;
        }
        
        if (s[i] == '-') flag = false;
        if (s[i] == '-' || s[i] == '+') i++;
        
        while (i < s.length() && isDigit(s[i])) {
            int r = s[i] - '0';
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && r > 7)) {
                return flag ? INT_MAX : INT_MIN;
            }
            res = res * 10 + r;
            i++;
        }
        
        return flag ? res : -res;
    }
    
    bool isDigit(char c) {
        if (c >= '0' && c <= '9') return true;
        else return false;
    }
};

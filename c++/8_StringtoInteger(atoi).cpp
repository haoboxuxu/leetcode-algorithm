class Solution {
public:
    int myAtoi(string s) {
        int k = 0;
        while (k < s.size() && s[k] == ' ') k++;
        if (k == s.size()) return 0;
        
        bool flag = true;
        if (s[k] == '-') flag = false, k++;
        else if (s[k] == '+') k++;
        
        int res = 0;
        while (k < s.size() && s[k] >= '0' && s[k] <= '9') {
            int x = s[k] - '0';
            if (flag && res > (INT_MAX - x) / 10) return INT_MAX;
            if (!flag && -res < (INT_MIN + x) / 10) return INT_MIN;
            if (-res * 10 - x == INT_MIN) return INT_MIN;
            res = res * 10 + x;
            k++;
        }
        return flag ? res : -res;
    }
};
class Solution {
public:
    int myAtoi(string s) {
        int k = 0;
        while (k < s.size() && s[k] == ' ') k++;

        bool flag = true;
        if (s[k] == '-') flag = false, k++;
        else if (s[k] == '+') k++;
        long long res = 0;
        while (k < s.size() && s[k] >= '0' && s[k] <= '9') {
            res = res * 10 + s[k] - '0';
            k++;
            if (res > INT_MAX) break;
        }

        res = flag ? res : -res;
        if (res > INT_MAX) res = INT_MAX;
        if (res < INT_MIN) res = INT_MIN;
        return res;
    }
};
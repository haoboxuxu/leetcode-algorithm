class Solution {
public:
    int strToInt(string str) {
        int k = 0;
        while (k < str.size() && str[k] == ' ') k++;

        bool flag = true;
        if (str[k] == '-') flag = false, k++;
        else if (str[k] == '+') k++;

        int res = 0;
        while (k < str.size() && str[k] >= '0' && str[k] <= '9') {
            int x = str[k] - '0';
            if (flag && res > (INT_MAX - x) / 10) return INT_MAX;
            if (!flag && -res < (INT_MIN + x) / 10) return INT_MIN;
            if (-res * 10 - x == INT_MIN) return INT_MIN;
            res = res * 10 + x;
            k++;
        }

        return flag ? res : -res;
    }
};

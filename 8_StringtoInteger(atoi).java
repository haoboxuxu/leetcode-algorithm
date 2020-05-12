class Solution {
    public int myAtoi(String str) {
        if (str == null || str.length() == 0) return 0;
        int res = 0;
        boolean flag = true;
        char[] s = str.toCharArray();
        int i = 0;
        while (s[i] == ' ' &&  (i+1) < s.length) {
            i++;
        }

        if (s[i] == '-') flag = false;
        if (s[i] == '-' || s[i] == '+') i++;

        while (i < s.length && isDigit(s[i])) {
            int r = s[i] - '0';
            if (res > Integer.MAX_VALUE / 10 || (res == Integer.MAX_VALUE / 10 && r > 7)) {
                return flag ? Integer.MAX_VALUE : Integer.MIN_VALUE;
            }
            res = res * 10 + r;
            i++;
        }

        return flag ? res : -res;
    }

    private boolean isDigit(char c) {
        if (c >= '0' && c <= '9') return true;
        else return false;
    }
}

class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        int pre = getValue(s[0]);
        for (int i = 1; i < s.size(); i++) {
            int cur = getValue(s[i]);
            if (pre < cur) {
                res -= pre;
            } else {
                res += pre;
            }
            pre = cur;
        }
        res += pre;
        return res;
    }
    
    int getValue(char ch) {
        switch(ch) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }
};



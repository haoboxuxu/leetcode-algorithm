class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> f(n + 1);
        s =  ' ' + s;
        f[0] = 1;
        for (int i = 1; i <= n; i++) {
            if (s[i] >= '1' && s[i] <= '9') f[i] += f[i - 1];
            if (i > 1) {
                int x = (s[i - 1] - '0') * 10 + (s[i] - '0');
                if (x >= 10 && x <= 26) f[i] += f[i - 2];
            }
        }
        return f[n];
    }
};
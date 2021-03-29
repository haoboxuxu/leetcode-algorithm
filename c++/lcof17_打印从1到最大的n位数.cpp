// c++ sol1
class Solution {
public:
    vector<int> printNumbers(int n) {
        int len = pow(10, n) - 1;
        vector<int> res(len);
        for (int i = 0; i < len; i++) {
            res[i] = i + 1;
        }
        return res;
    }
};
// c++ sol2
class Solution {
public:
    void dfs(int n, int deep, string s, vector<int>& res) {
        if (deep == n) {
            int val = std::stoi(s);
            if (val != 0) res.push_back(val);
            return;
        }
        for (int i = 0; i < 10; i++) {
            s[deep] = '0' + i;
            dfs(n, deep+1, s, res);
        }
    }
    vector<int> printNumbers(int n) {
        vector<int> res;
        string s(n, '0');
        dfs(n, 0, s, res);
        return res;
    }
};

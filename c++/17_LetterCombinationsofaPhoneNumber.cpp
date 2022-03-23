class Solution {
public:
    vector<string> res;
    string path;
    string strs[10] = {
        "", "", "abc", "def",
        "ghi", "jkl", "mno",
        "pqrs", "tuv", "wxyz",
    };
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return res;
        dfs(digits, 0);
        return res;
    }

    void dfs(string& digits, int u) {
        if (u == digits.size()) {
            res.push_back(path);
            return;
        }
        for (auto c : strs[digits[u] - '0']) {
            path.push_back(c);
            dfs(digits, u + 1);
            path.pop_back();
        }
    }
};
class Solution {
public:
    vector<string> res;
    string strs[10] = {
        "", "", "abc", "def",
        "ghi", "jkl", "mno",
        "pqrs", "tuv", "wxyz",
    };
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return res;
        dfs(digits, 0, "");
        return res;
    }
    
    void dfs(string& digits, int depth, string path) {
        if (depth == digits.size()) {
            res.push_back(path);
        } else {
            for (auto c : strs[digits[depth] - '0']) {
                dfs(digits, depth+1, path+c);
            }
        }
    }
};

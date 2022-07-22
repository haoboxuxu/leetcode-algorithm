# [剑指 Offer 38. 字符串的排列](https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof/)

输入一个字符串，打印出该字符串中字符的所有排列。

 

你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。

 

示例:

输入：s = "abc"
输出：["abc","acb","bac","bca","cab","cba"]


限制：

1 <= s 的长度 <= 8

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

```c++
class Solution {
public:
    vector<string> res;
    vector<bool> vis;
    vector<string> permutation(string s) {
        sort(s.begin(), s.end());
        vis = vector<bool>(s.size());
        dfs(s, "", 0);
        return res;
    }

    void dfs(string& s, string path, int u) {
        if (u == s.size()) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < s.size(); i++) {
            if (i && s[i] == s[i - 1] && !vis[i - 1]) continue;
            if (!vis[i]) {
                vis[i] = true;
                path.push_back(s[i]);
                dfs(s, path, u + 1);
                vis[i] = false;
                path.pop_back();
            }
        }
    }
};
```


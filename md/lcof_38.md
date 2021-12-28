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
        vis.resize(s.length());
        for (int i = 0; i < s.length(); i++) vis[i] = false;
        sort(s.begin(), s.end());
        string path;
        dfs(s, 0, path);
        return res;
    }
    
    void dfs(string& s, int idx, string& path) {
        if (idx == s.length()) {
            res.push_back(path);
            return;
        }
        
        for (int i = 0; i < s.length(); i++) {
            if (i > 0 && !vis[i - 1] && s[i - 1] == s[i]) {
                continue;
            }
            if (!vis[i]) {
                path.push_back(s[i]);
                vis[i] = true;
                dfs(s, idx+1, path);
                path.pop_back();
                vis[i] = false;
            }
        }
    }
};
```


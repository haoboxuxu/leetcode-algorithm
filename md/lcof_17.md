# [剑指 Offer 17. 打印从1到最大的n位数](https://leetcode-cn.com/problems/da-yin-cong-1dao-zui-da-de-nwei-shu-lcof/)

输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。

示例 1:

输入: n = 1
输出: [1,2,3,4,5,6,7,8,9]


说明：

用返回一个整数列表来代替打印
n 为正整数

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/da-yin-cong-1dao-zui-da-de-nwei-shu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

```c++
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
```


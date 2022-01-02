# [剑指 Offer 49. 丑数](https://leetcode-cn.com/problems/chou-shu-lcof/)

我们把只包含质因子 2、3 和 5 的数称作丑数（Ugly Number）。求按从小到大的顺序的第 n 个丑数。

 

示例:

输入: n = 10
输出: 12
解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
说明:  

1 是丑数。
n 不超过1690。
注意：本题与主站 264 题相同：https://leetcode-cn.com/problems/ugly-number-ii/

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/chou-shu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

```c++
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> v;
        v.push_back(1);
        for (int i = 0, j = 0, k = 0; v.size() < n;) {
            int t = min(v[i] * 2, min(v[j] * 3, v[k] * 5));
            v.push_back(t);
            if (v[i] * 2 == t) i++;
            if (v[j] * 3 == t) j++;
            if (v[k] * 5 == t) k++;
        }
        return v.back();
    }
};
```


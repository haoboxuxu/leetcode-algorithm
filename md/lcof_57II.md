# [剑指 Offer 57 - II. 和为s的连续正数序列](https://leetcode-cn.com/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/)

输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。

序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。

 

示例 1：

输入：target = 9
输出：[[2,3,4],[4,5]]
示例 2：

输入：target = 15
输出：[[1,2,3,4,5],[4,5,6],[7,8]]


限制：

1 <= target <= 10^5

```c++
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        for (int i = 1, j = 1, sum = 1; i <= target; i++) {
            while (sum < target) j++, sum += j;
            if (sum == target && j > i) {
                vector<int> path;
                for (int k = i; k <= j; k++) path.push_back(k);
                res.push_back(path);
            }
            sum -= i;
        }
        return res;
    }
};
```


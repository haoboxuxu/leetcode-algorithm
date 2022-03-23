# [剑指 Offer 51. 数组中的逆序对](https://leetcode-cn.com/problems/shu-zu-zhong-de-ni-xu-dui-lcof/)

在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。

 

示例 1:

输入: [7,5,6,4]
输出: 5


限制：

0 <= 数组长度 <= 50000



来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shu-zu-zhong-de-ni-xu-dui-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

```c++
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return merge(nums, 0, nums.size() - 1);
    }

    int merge(vector<int>& nums, int l, int r) {
        if (l >= r) return 0;
        int mid = (l + r) >> 1;
        int res = merge(nums, l, mid) + merge(nums, mid + 1, r);
        int i = l, j = mid + 1;
        vector<int> t;
        while (i <= mid && j <= r) {
            if (nums[i] > nums[j]) {
                t.push_back(nums[i++]);
                res += r - j + 1;
            } else {
                t.push_back(nums[j++]);
            }
        }
        while (i <= mid) t.push_back(nums[i++]);
        while (j <= r) t.push_back(nums[j++]);
        int k = l;
        for (auto x : t) nums[k++] = x;
        return res;
    }
};
```


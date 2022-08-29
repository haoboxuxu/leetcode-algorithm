# [剑指 Offer 40. 最小的k个数](https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/)

输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。

 

示例 1：

输入：arr = [3,2,1], k = 2
输出：[1,2] 或者 [2,1]
示例 2：

输入：arr = [0,1,2,1], k = 1
输出：[0]


限制：

0 <= k <= arr.length <= 10000
0 <= arr[i] <= 10000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

```c++
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        quicksort(arr, 0, arr.size() - 1, k);
        vector<int> res(k);
        for (int i = 0; i < k; i++) res[i] = arr[i];
        return res;
    }

    void quicksort(vector<int>& arr, int l, int r, int k) {
        if (l >= r) return;
        int i = l - 1, j = r + 1, x = arr[l + r >> 1];
        while (i < j) {
            do i++; while (arr[i] < x);
            do j--; while (arr[j] > x);
            if (i < j) swap(arr[i], arr[j]);
        }
        int len = j - l + 1;
        if (k <= len) quicksort(arr, l, j, k);
        else quicksort(arr, j + 1, r, k - len);
    }
};
```


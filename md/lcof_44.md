# [剑指 Offer 44. 数字序列中某一位的数字](https://leetcode-cn.com/problems/shu-zi-xu-lie-zhong-mou-yi-wei-de-shu-zi-lcof/)

数字以0123456789101112131415…的格式序列化到一个字符序列中。在这个序列中，第5位（从下标0开始计数）是5，第13位是1，第19位是4，等等。

请写一个函数，求任意第n位对应的数字。

 

示例 1：

输入：n = 3
输出：3
示例 2：

输入：n = 11
输出：0


限制：

0 <= n < 2^31
注意：本题与主站 400 题相同：https://leetcode-cn.com/problems/nth-digit/



来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shu-zi-xu-lie-zhong-mou-yi-wei-de-shu-zi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

```c++
class Solution {
public:
    int findNthDigit(int n) {
        long long k = 1, t = 9, s = 1;
        while (n > k * t) {
            n -= k * t;
            k++;
            t *= 10;
            s *= 10;
        }
        s += (n + k - 1) / k - 1;
        n = n % k ? n % k : k;
        return to_string(s)[n - 1] - '0';
    }
};
```


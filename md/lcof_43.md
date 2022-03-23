# [剑指 Offer 43. 1～n 整数中 1 出现的次数](https://leetcode-cn.com/problems/1nzheng-shu-zhong-1chu-xian-de-ci-shu-lcof/)

输入一个整数 n ，求1～n这n个整数的十进制表示中1出现的次数。

例如，输入12，1～12这些整数中包含1 的数字有1、10、11和12，1一共出现了5次。

 

示例 1：

输入：n = 12
输出：5
示例 2：

输入：n = 13
输出：6


限制：

1 <= n < 2^31
注意：本题与主站 233 题相同：https://leetcode-cn.com/problems/number-of-digit-one/

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/1nzheng-shu-zhong-1chu-xian-de-ci-shu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

```c++
class Solution {
public:
    int countDigitOne(int n) {
        if (n <= 0) return 0;
        vector<int> nums;
        while (n) {
            nums.push_back(n % 10);
            n /= 10;
        }
        reverse(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            int d = nums[i];
            int left = 0, right = 0, p = 1;
            for (int j = 0; j < i; j++) {
                left = left * 10 + nums[j];
            }
            for (int j = i + 1; j < nums.size(); j++) {
                right = right * 10 + nums[j];
                p *= 10;
            }
            if (d == 0) res += left * p;
            else if (d == 1) res += left * p + right + 1;
            else res += (left + 1) * p;
        }
        return res;
    }
};
```


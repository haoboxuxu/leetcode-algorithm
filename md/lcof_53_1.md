# [剑指 Offer 53 - I. 在排序数组中查找数字 I](https://leetcode-cn.com/problems/zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof/)

统计一个数字在排序数组中出现的次数。

 

示例 1:

输入: nums = [5,7,7,8,8,10], target = 8
输出: 2
示例 2:

输入: nums = [5,7,7,8,8,10], target = 6
输出: 0


提示：

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums 是一个非递减数组
-109 <= target <= 109


注意：本题与主站 34 题相同（仅返回值不同）：https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

```c++
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int leftIdx = binSearch(nums, target, true);
        int rightIdx = binSearch(nums, target, false)-1;
        if (leftIdx <= rightIdx && rightIdx < nums.size() && nums[leftIdx] == target && nums[rightIdx] == target) {
            return rightIdx - leftIdx + 1;
        }
        return 0;
    }
    
    int binSearch(vector<int>& nums, int target, bool lower) {
        int l = 0, r = (int)nums.size()-1, index = (int)nums.size();
        while (l <= r) {
            int m = l + r >> 1;
            if (nums[m] > target || (lower && nums[m] >= target)) {
                r = m - 1;
                index = m;
            } else {
                l = m + 1;
            }
        }
        return index;
    }
};
```

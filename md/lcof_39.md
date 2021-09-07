# [剑指 Offer 39. 数组中出现次数超过一半的数字](https://leetcode-cn.com/problems/shu-zu-zhong-chu-xian-ci-shu-chao-guo-yi-ban-de-shu-zi-lcof/)

数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。

 

你可以假设数组是非空的，并且给定的数组总是存在多数元素。

 

示例 1:

输入: [1, 2, 3, 2, 2, 2, 5, 4, 2]
输出: 2


限制：

1 <= 数组长度 <= 50000

 

注意：本题与主站 169 题相同：https://leetcode-cn.com/problems/majority-element/

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shu-zu-zhong-chu-xian-ci-shu-chao-guo-yi-ban-de-shu-zi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

```c++
// best
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = -1;
        int count = 0;
        for (auto num : nums) {
            if (num == candidate) {
                count++;
            } else if (--count < 0) {
                candidate = num;
                count = 1;
            }
        }
        return candidate;
    }
};
//sol1
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        int res = 0, size = (int)nums.size();
        for (int num : nums) {
            mp[num]++;
            if (mp[num] >= (size+1)/2) {
                res = num;
            }
        }
        return res;
    }
};
//sol2
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};
//sol3
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        while (1) {
            int candidate = nums[rand() % nums.size()];
            int count = 0;
            for (int num : nums) {
                if (num == candidate) count++;
                if (count > nums.size() / 2) return candidate;
            }
        }
        return 0;
    }
};
//sol4
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        return majorityElementRec(nums, 0, (int)nums.size() - 1);
    }
    
    int majorityElementRec(vector<int>& nums, int lo, int hi) {
        if (lo == hi) {
            return nums[lo];
        }
        int mid = (hi - lo) / 2 + lo;
        int leftMajority = majorityElementRec(nums, lo, mid);
        int rightMajority = majorityElementRec(nums, mid+1, hi);
        if (countInRange(nums, leftMajority, lo, hi) > (hi-lo+1)/2) {
            return leftMajority;
        }
        if (countInRange(nums, rightMajority, lo, hi) > (hi-lo+1)/2) {
            return rightMajority;
        }
        return 0;
    }
    
    int countInRange(vector<int>& nums, int target, int lo, int hi) {
        int count = 0;
        for (int i = lo; i <= hi; i++) {
            if (nums[i] == target) {
                count++;
            }
        }
        return count;
    }
    
};
```


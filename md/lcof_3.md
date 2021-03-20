# [剑指 Offer 03. 数组中重复的数字](https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/)

找出数组中重复的数字。


在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。

示例 1：

输入：
[2, 3, 1, 0, 2, 5, 3]
输出：2 或 3 


限制：

2 <= n <= 100000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

```cpp
// c++ sol1
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_map<int, int> map;
        for (auto& num : nums) {
            map[num]++;
            if (map[num] > 1) return num;
        }
        return 0;
    }
};
// c++ sol2
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_set<int> set;
        set.reserve(nums.size() * 2);
        
        for (auto& num : nums) {
            auto iter = set.insert(num);
            if (iter.second == false) return num;
        }
        return 0;
    }
};
// c++ sol3
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i-1]) {
                return nums[i];
            }
        }
        return 0;
    }
};
// c++ sol4
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (i == nums[i]) {
                continue;
            }
            if (nums[i] == nums[nums[i]]) {
                return nums[i];
            }
            //swap
            int tmp = nums[nums[i]];
            nums[nums[i]] = nums[i];
            nums[i] = tmp;
            i--;
        }
        return 0;
    }
};

// java
//5 ms
class Solution {
    public int findRepeatNumber(int[] nums) {
        Set<Integer> set = new HashSet<>();
        for (int num : nums) {
            if (!set.add(num)) {
                return num;
            }
        }
        return -1;
    }
}
//3 ms
class Solution {
    public int findRepeatNumber(int[] nums) {
        Arrays.sort(nums);
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] == nums[i-1]) {
                return nums[i];
            }
        }
        return -1;
    }
}
//2 ms
class Solution {
    public int findRepeatNumber(int[] nums) {
        int len = nums.length;
        //长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内
        int[] tmp = new int[len];
        for (int i = 0; i < len; i++) {
            tmp[nums[i]] += 1;
            if (tmp[nums[i]] > 1) {
                return nums[i];
            }
        }
        return -1;
    }
}

//1 ms
class Solution {
    public int findRepeatNumber(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            if (i == nums[i]) {
                continue;
            }
            if (nums[i] == nums[nums[i]]) {
                return nums[i];
            }
            //swap
            int tmp = nums[nums[i]];
            nums[nums[i]] = nums[i];
            nums[i] = tmp;
            i--;
        }
        return -1;
    }
}
```


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
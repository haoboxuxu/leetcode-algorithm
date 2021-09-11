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

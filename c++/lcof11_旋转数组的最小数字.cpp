class Solution {
public:
    int minArray(vector<int>& nums) {
        int R = nums.size() - 1;
        while (R > 0 && nums[R] == nums[0]) R--;
        int l = 0, r = R;
        if (nums[l] <= nums[r]) return nums[l];
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] < nums[0]) r = mid;
            else l = mid + 1;
        }
        return nums[l];
    }
};
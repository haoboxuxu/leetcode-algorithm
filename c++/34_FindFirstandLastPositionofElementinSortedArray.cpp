class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1, -1};
        vector<int> res(2);
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        if (nums[l] != target) return {-1, -1};
        res[0] = l;
        l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (nums[mid] <= target) l = mid;
            else r = mid - 1;
        }
        res[1] = l;
        return res;
    }
};
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int res1 = binSearch(nums, target, true);
        int res2 = binSearch(nums, target, false) - 1;
        
        if (res1 <= res2 && res2 < nums.size() && nums[res1] == target && nums[res2] == target) {
            return vector<int>{res1, res2};
        }
        
        return vector<int>{-1, -1};
    }
    
    int binSearch(vector<int>& nums, int target, bool lower) {
        int l = 0, r = nums.size() - 1, res = nums.size();
        
        while (l <= r) {
            int mid  = (l + r) / 2;
            if (nums[mid] > target || (lower && nums[mid] >= target)) {
                r = mid - 1;
                res = mid;
            } else {
                l = mid + 1;
            }
        }
        return res;
    }
};

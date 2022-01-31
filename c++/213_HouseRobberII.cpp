class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (nums.empty()) return 0;
        else if (n == 1) return nums[0];
        else if (n == 2) return max(nums[0], nums[1]);
        return max(rob1(nums, 0, n - 2), rob1(nums, 1, n - 1));
    }
    
    int rob1(vector<int>& nums, int l, int r) {
        int f = nums[l], s = max(nums[l], nums[l+1]);
        for (int i = l+2; i <= r; i++) {
            int t = s;
            s = max(f + nums[i], s);
            f = t;
        }
        return s;
    }
};

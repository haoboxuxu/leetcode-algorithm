class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        int farthest = 0;
        for (int i = 0; i < len; i++) {
            if (i <= farthest) {
                farthest = max(farthest, i+nums[i]);
                if (farthest >= len-1) return true;
            } else {
                break;
            }
        }
        return false;
    }
};

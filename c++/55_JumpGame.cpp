class Solution {
public:
    bool canJump(vector<int>& nums) {
        for (int i = 0, j = 0; i < nums.size(); i++) {
            if (j < i) return false;
            j = max(j, i + nums[i]);
        }
        return true;
    }
};
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i, j;
        for (i = 0, j = 0; j < nums.size(); j++) {
            if (nums[j] != 0) {
                nums[i++] = nums[j];
            }
        }
        while (i < nums.size()) nums[i++] = 0;
    }
};
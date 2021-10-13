class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return 0;
        int slow = 1, fast = 1;
        while (fast < len) {
            if (nums[fast] != nums[fast-1]) {
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }
        return slow;
    }
};

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (!n) return 0;
        int i = 1, j = 1;
        while (j < n) {
            if (nums[j] != nums[j-1]) {
                nums[i] = nums[j];
                i++;
            }
            j++;
        }
        return i;
    }
};

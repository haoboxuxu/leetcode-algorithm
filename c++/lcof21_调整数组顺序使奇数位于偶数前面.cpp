class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = n - 1;
        while (i < j) {
            while (i < j && (nums[i] & 1) == 1) i++;
            while (i < j && (nums[j] & 1) == 0) j--;
            swap(nums[i], nums[j]);
        }
        return nums;
    }
};
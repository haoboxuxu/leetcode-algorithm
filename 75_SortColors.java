class Solution {
    public void sortColors(int[] nums) {
        int len = nums.length;

        if (len < 2) {
            return;
        }

        // all in [0, p0] = 0
        // all in (p0, i) = 1
        // all in [p2, len) = 2
        int p0 = -1;
        int i = 0;
        int p2 = len;

        while (i < p2) {
            if (nums[i] == 0) {
                p0++;
                swap(nums, i, p0);
                i++;
            }else if (nums[i] == 1) {
                i++;
            }else {
                p2--;
                swap(nums, i, p2);
            }
        }
    }

    private void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}

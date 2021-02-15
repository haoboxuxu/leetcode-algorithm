class Solution {
    public int minSubArrayLen(int s, int[] nums) {
        int len = nums.length;
        if (len == 0) {
            return 0;
        }
        int res = Integer.MAX_VALUE;
        int i = 0, j = 0;
        int sum = 0;
        while (j < len) {
            sum += nums[j];
            while (sum >= s) {
                res = Math.min(res, j - i + 1);
                sum -= nums[i];
                i++;
            }
            j++;
        }
        return res == Integer.MAX_VALUE ? 0 : res;
    }
}

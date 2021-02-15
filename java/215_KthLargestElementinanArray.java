class Solution {
    public int findKthLargest(int[] nums, int k) {
        if (nums == null || nums.length == 0) {
            return Integer.MAX_VALUE;
        }
        return dc(nums, 0, nums.length - 1, k - 1);
    }

    public int dc(int[] nums, int start, int end, int k) {
        if (start == end) return nums[start];
        //int[] ps = partition(nums, start, end, nums[start]);
        int[] ps = partition(nums, start, end, nums[start + (int) (Math.random() * (end - start + 1))]);
        if (k >= ps[0] && k <= ps[1]) {
            return nums[k];
        }else if (k < ps[0]) {
            return dc(nums, start, ps[0] - 1, k);
        }else {
            return dc(nums, ps[0] + 1, end, k);
        }
    }

    public static int[] partition(int[] nums, int start, int end, int num) {
        int less = start - 1;
        int more = end + 1;
        int cur = start;
        while (cur < more) {
            if (nums[cur] > num) {
                swap(nums, ++less, cur++);
            }else if (nums[cur] < num) {
                swap(nums, --more, cur);
            }else {
                cur++;
            }
        }
        return new int[] {less + 1, more - 1};
    }


    private static void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}

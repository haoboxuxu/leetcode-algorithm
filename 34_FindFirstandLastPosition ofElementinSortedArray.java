class Solution {
    public int[] searchRange(int[] nums, int target) {
        int len = nums.length;
        if (len == 0) {
            return new int[]{-1, -1};
        }

        int firstPos = findFirstPos(nums, target);
        if (firstPos == -1) {
            return new int[]{-1, -1};
        }

        int lastPos = findLastPos(nums, target);
        return new int[] {firstPos, lastPos};
    }

    private int findFirstPos(int[] nums, int target) {
        int left = 0, right = nums.length - 1;
        while (left < right) {
            int mid = (left + right) >>> 1;
            if (nums[mid] < target) {
                left = mid + 1;
            }else if (nums[mid] == target) {
                right = mid;
            }else {
                right = mid - 1;
            }
        }
        if (nums[left] == target) return left;
        return -1;
    }

    private int findLastPos(int[] nums, int target) {
        int left = 0, right = nums.length - 1;
        while (left < right) {
            int mid = (left + right + 1) >>> 1;
            if (nums[mid] < target) {
                left = mid + 1;
            }else if (nums[mid] == target) {
                left = mid;
            }else {
                right = mid - 1;
            }
        }
        return left;
    }
}

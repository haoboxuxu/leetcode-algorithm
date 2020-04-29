class Solution {
    public int maxArea(int[] height) {
        if (height == null || height.length == 0) return 0;
        int len = height.length;
        int l = 0, r = len - 1;
        int res = 0;

        while (l < r) {
            int h = Math.min(height[l], height[r]);
            res = Math.max(res, h * (r - l));
            if (height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        }

        return res;
    }
}

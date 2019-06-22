class Solution {
    public int maxSubArray(int[] nums) {
    	int len = nums.length;
    	if(len == 0 || nums == null) return 0;
    	
    	int sum = 0;
    	int res = Integer.MIN_VALUE;
    	
    	for(int i = 0; i < len; i++) {
    		sum = Math.max(nums[i], nums[i] + sum);
    		res = Math.max(res, sum);
    	}
    	return res;
    }
}

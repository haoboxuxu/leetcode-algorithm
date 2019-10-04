class Solution {
    public int findDuplicate(int[] nums) {
    	int n = nums.length;
        boolean[] mark = new boolean[n];
        int res = 0;
        for(int i = 0; i < n; i++) {
        	if(mark[nums[i]] == true) {
                return nums[i];
        	}else {
				mark[nums[i]] = true;
			}
        }
        return -1;
    }
}

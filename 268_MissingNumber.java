class Solution {
	public int missingNumber(int[] nums) {
		int n = nums.length;
		int res = (n+0)*(n+1)/2;
		for (int num : nums){
			res -= num;
		}
		return res;
	 }
}

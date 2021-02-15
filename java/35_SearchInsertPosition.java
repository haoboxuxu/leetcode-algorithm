class Solution {
	 public static int searchInsert(int[] nums, int target) {
	        if(nums.length == 0 || nums == null) {
	        	return 0;
	        }
	        int l = 0;
	        int r = nums.length - 1;
	        int ans = 0;
	        while(l < r + 1) {
	        	int mid = (r - l)/2 + l;
	        	ans = mid;
	        	if(nums[mid] == target) {
	        		break;
	        	}
	        	if(target < nums[mid]) {
	        		r = mid -1;
	        	}else {
					l = mid + 1;
				}
	        }
	        if(nums[ans] == target) {
	        	return ans;
	        }else if(nums[ans] > target) {
				return ans;
			}else {
				return ans + 1;
			}
	  }
}

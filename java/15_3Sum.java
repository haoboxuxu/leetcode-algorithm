class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
    	List<List<Integer>> res = new ArrayList<List<Integer>>();
    	Arrays.sort(nums);
    	if(nums.length == 0 || nums == null) {
    		return res;
    	}
    	for(int index = 0; index < nums.length; index++) {
    		//找到负数
    		if(nums[index] > 0) {
    			break;
    		}
    		if(index > 0 && nums[index] == nums[index - 1]) {
    			continue;
    		}
    		int target = - nums[index];
    		//双指针
    		int i = index + 1;
    		int j = nums.length - 1;
    		while(i < j) {
    			if(nums[i] + nums[j] == target) {
    				List<Integer> temp = new ArrayList<Integer>();
    				temp.add(nums[index]);
    				temp.add(nums[i]);
    				temp.add(nums[j]);
    				res.add(temp);
    				while (i < j && nums[i] == nums[i + 1]) ++i;
                    while (i < j && nums[j] == nums[j - 1]) --j;
    				i++;
    				j--;
    			}else if(nums[i] + nums[j] > target) {
    				j--;
    			}else {
    				i++;
    			}
    		}
    		
    	}
    	return res;
    }
}

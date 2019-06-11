class Solution {
    public static List<List<Integer>> permute(int[] nums) {
    	List<List<Integer>> res = new ArrayList<List<Integer>>();
    	 dfs(res, nums, 0);
    	 return res;
    }
    public static void dfs(List<List<Integer>> res, int[] nums, int index) {
    	if(index == nums.length) {
    		List<Integer> temp = new ArrayList<Integer>();
    		for(int i : nums) {
    			temp.add(i);
    		}
    		res.add(temp);
    	}else {
    		for(int i = index; i < nums.length; i++) {
    			swap(nums, index, i);
    			dfs(res, nums, index + 1);
    			swap(nums, index, i);
    		}
    	}
    }
    public static void swap(int a[], int i, int j) {
    	int temp = a[i];
    	a[i] = a[j];
    	a[j] = temp; 
    }
    public static void main(String[] args) {
    	int[] nums = {1, 2, 3};
    	System.out.println(permute(nums));
	}
}

class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        int len = candidates.length;
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> list = new ArrayList<Integer>();
        if(candidates.length == 0 || candidates == null) return ans;
        
        Arrays.sort(candidates);
        handle(ans, list, candidates, target, 0);
        return ans;
    }
    
    private boolean handle(List<List<Integer>> ans, List<Integer> list, int[] candidates, int target, int start) {
		if(target < 0) {
			return false;
		}else if (target == 0) {
			List<Integer> temp = new ArrayList<Integer>(list);
			ans.add(temp);
			return true;
		}else {
			for (int i = start; i < candidates.length; i++) {
				list.add(candidates[i]);
				boolean b = handle(ans, list, candidates, target - candidates[i], i);
				list.remove(list.size() - 1);
				if(!b) break;
			}
		}
		return true;
	}
}

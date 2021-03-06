//sol binary
class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();

        int len = nums.length;

        for (int i = (int)Math.pow(2, len); i < (int)Math.pow(2, len+1); i++) {
            String i2b = Integer.toBinaryString(i).substring(1);
            
            List<Integer> cur = new ArrayList<>();

            for (int j = 0; j < len; j++) {
                if (i2b.charAt(j) == '1') {
                    cur.add(nums[j]);
                }
            }
            res.add(cur);
        }
        return res;
    }
}
//sol dfs
class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();

        res.add(new ArrayList<Integer>());

        for (int num : nums) {
            List<List<Integer>> curSubsets = new ArrayList<>();
            for (List<Integer> subset : res) {
                List<Integer> curSubset =  new ArrayList<>(subset);
                curSubset.add(num);
                curSubsets.add(curSubset);
            }
            res.addAll(curSubsets);
        }

        return res;
    }
}

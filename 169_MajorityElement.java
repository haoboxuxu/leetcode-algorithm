//damn slow
/*
class Solution {
    public int majorityElement(int[] nums) {
        Map<Integer, Integer> mp = new HashMap<>();
        int res = 0;
        int curRes = 0;
        for(int num : nums){
          int count = mp.getOrDefault(num, 0) + 1;
          mp.put(num, count);
          if(count > curRes) {
              curRes = count;
              res = num;
          }
        }
        return res;
    }
}
*/

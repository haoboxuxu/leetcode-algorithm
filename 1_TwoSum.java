import java.util.HashMap;

public class Solution {
     public static int[] twoSum(int[] nums, int target) {
       HashMap<Integer, Integer> hm = new HashMap<>();
       int[] res = new int[2];

       for(int i = 0; i < nums.length; ++i){
           hm.put(nums[i] ,i);
       }

       for(int i = 0; i < nums.length; ++i){
           int t = target - nums[i];
           if(hm.containsKey(t) && hm.get(t) != i){
                   res[0] = i;
                   res[1] = hm.get(t);
                   break;
           }
       }
       return res;
    }
}

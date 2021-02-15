class Solution {
    public int singleNumber(int[] array) {
        int res = 0;
        for(int num : array){
            res = res ^ num;
        }
        return res;
    }
}

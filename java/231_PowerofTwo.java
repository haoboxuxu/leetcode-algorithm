class Solution {
    public boolean isPowerOfTwo(int n) {
        int flag = 0;
        while(n > 0){
            flag += (n&1);
            n >>= 1;
        }
        return flag == 1;
    }
}

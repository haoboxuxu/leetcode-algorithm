class Solution {
    public static int mySqrt(int x) {
        if(x == 0 || x == 1) {
        	return x;
        }
        int l = 1, r = x;
        int res = 0;
        
        while(l <= r) {
        	long mid = (r - l) / 2 + l;
        	if(mid * mid == (long)x) {
        		return (int)mid;
        	}
        	if(mid * mid < (long)x){
        		l = (int)(mid + 1);
        		res = (int)mid;
        	}else {
				r = (int)(mid - 1);
			}
        }
        return res;
    }
    public static void main(String[] args) {
		System.out.println(mySqrt(8));
	}
}

class Solution {
	public int[] plusOne(int[] digits) {
		digits[digits.length - 1] += 1;
		int a = 0;
		for (int i = digits.length - 1; i >= 0; i--) {
			digits[i] += a;
			a = digits[i] / 10;
			digits[i] %= 10;
		}
		if(a == 0)
			return digits;
		int[] res = new int[digits.length + 1];
		for(int i = 0; i < digits.length; i++) {
			res[i+1] = digits[i];
		}
		res[0] = a;
		return res;
	}
}

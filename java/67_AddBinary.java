class Solution {
    public static String addBinary(String a, String b) {
    	StringBuilder res = new StringBuilder();
    	int carry = 0;
    	int lenA = a.length() - 1;
    	int lenB = b.length() - 1;
    	while (lenA >= 0 || lenB >= 0) {
			int aIndex = lenA < 0? 0 : (a.charAt(lenA--) - '0');
			int bIndex = lenB < 0? 0 : (b.charAt(lenB--) - '0');
			int carryOut = (aIndex & bIndex) | (aIndex & carry) | (bIndex & carry);
			res.append(aIndex ^ bIndex ^ carry);
			carry = carryOut;
		}
    	if(carry == 1) {
    		return res.append(carry).reverse().toString();
    	}else {
    		return res.reverse().toString();	
    	}
    }
    
    public static void main(String[] args) {
		System.out.println(addBinary("100", "10"));
	}
}

class Solution {
    public static String multiply(String num1, String num2) {
    	int len1 = num1.length();
    	int len2 = num2.length();
    	
    	int[] ans = new int[len1 + len2];
    	
    	for(int i = len1 - 1; i >= 0; i--) {
    		for(int j = len2 - 1;  j >= 0; j--) {
    			int mul = (num1.charAt(i) - '0') * (num2.charAt(j) - '0');
    			int ans1 = i + j;
    			int ans2 = i + j + 1;
    			int sum = mul + ans[ans2];
    			
    			ans[ans1] += sum/10;
    			ans[ans2] = sum % 10;
    		}
    	}
    	
    	StringBuilder res = new StringBuilder();
    	for(int i : ans) {
    		if(!(res.length() == 0 && i == 0)) {
    			res.append(i);
    		}
    	}
    	return res.length() == 0? "0" : res.toString();
    }
}

/*old version
class Solution {
    public static String multiply(String num1, String num2) {
    	int len1 = num1.length();
    	int len2 = num2.length();
    	
    	int[] ans = new int[len1 + len2];
    	
    	for(int i = len1 - 1; i >= 0; i--) {
    		for(int j = len2 - 1;  j >= 0; j--) {
    			int mul = (num1.charAt(i) - '0') * (num2.charAt(j) - '0');
    			int ans1 = i + j;
    			int ans2 = i + j + 1;
    			int sum = mul + ans[ans2];
    			
    			ans[ans1] += sum/10;
    			ans[ans2] = sum % 10;
    		}
    	}
    	
    	String res = "";
    	for(int s : ans) {
    			res += (char)(s + '0');
    	}
    	System.out.println(res);
    	int mark = -1;
    	for(int i = 0; i < res.length(); i++) {
    		if(res.charAt(i) >= '1' && res.charAt(i) <= '9') {
    			mark = i - 1;
    			break;
    		}
    	}
    	if(res.charAt(0) != '0') {
    	}else if(mark != -1){
    		res = res.substring(mark + 1, res.length());
    	}else {
    		res = "";
    	}
    	return res.length() == 0? "0" : res;
    }
}
*/

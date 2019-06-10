public class Solution {
    public static List<String> generateParenthesis(int n) {
    	List<String> res = new ArrayList<String>();
    	handdle(n, n, "", res);
    	return res;
    }
    public static void handdle(int l, int r, String s, List<String> res) {
    	if(l < 0 || r < 0 || l > r) {
    		return;
    	}
    	if(l == 0 && r == 0) {
    		res.add(s);
    	}
    	handdle(l - 1, r, s + "(", res);
    	handdle(l, r - 1, s + ")", res);
    }
}

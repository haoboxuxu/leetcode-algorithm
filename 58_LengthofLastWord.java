class Solution {
    public int lengthOfLastWord(String s) {
        int len = s.length();
        int ans = 0;
        for(int i = len - 1; i >= 0; i--) {
        	if(s.charAt(i) == ' ') {
        		len--;
        	}else {
        		break;
        	}
        }
        for(int i = len - 1; i >= 0; i--) {
        	if(s.charAt(i) != ' ') {
        		ans++;
        	}else {
				break;
			}
        }
        return ans;
    }
}

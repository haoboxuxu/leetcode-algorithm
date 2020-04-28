class Solution {
    public String longestPalindrome(String s) {
        if (s.length() == 0 || s == null) return s;
        int len = s.length();
        boolean[][] dp = new boolean[len + 1][len + 2];
        int res_i = 0, res_j = 0;

        for (int i = len - 2; i >= 0; i--) {
            dp[i][i] = true;
            for (int j = i + 1; j < len; j++) {
                dp[i][j] = s.charAt(i) == s.charAt(j) && (j - i < 3 || dp[i + 1][j - 1]);
                if (dp[i][j] && res_j - res_i < j - i) {
                    res_i = i;
                    res_j = j;
                }
            }
        }

        return s.substring(res_i, res_j + 1);
    }
}

class Solution {
    List<String> res = new ArrayList<>();
    public List<String> removeInvalidParentheses(String s) {
        if (s == null) {
            return res;
        }
        int l = 0, r = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                l += 1;
            }else if (s.charAt(i) == ')' && l > 0) {
                l -= 1;
            }else if (s.charAt(i) == ')') {
                r += 1;
            }
        }
        dfs(0, new StringBuilder(), 0, l + r, s);
        return res;
    }
    private void dfs(int i, StringBuilder sb, int l, int miss, String s) {
        if (i == s.length() && l == 0) {
            res.add(sb.toString());
        }else if(i < s.length() && l >= 0) {
            char c = s.charAt(i);
            int  leftChange = c == '(' ? 1 : c == ')' ? -1 : 0;
            sb.append(c);
            dfs(i + 1, sb, l + leftChange, miss, s);
            sb.deleteCharAt(sb.length() - 1);
            if (miss > 0 && !(sb.length() > 0 && s.charAt(i) == sb.charAt(sb.length() - 1)) && (c == ')' || c == '(')) {
                dfs(i + 1, sb, l, miss - 1, s);
            }
        }
    }
}

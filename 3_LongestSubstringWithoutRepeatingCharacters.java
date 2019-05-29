class Solution {
    public int lengthOfLongestSubstring(String s) {
        int res = 0, left = 0, right = 0;
        HashSet<Character> hs = new HashSet<>();
        while (right < s.length()) {
            if (!hs.contains(s.charAt(right))) {
                hs.add(s.charAt(right++));
                res = Math.max(res, hs.size());
            } else {
                hs.remove(s.charAt(left++));
            }
        }
        return res;
    }
}

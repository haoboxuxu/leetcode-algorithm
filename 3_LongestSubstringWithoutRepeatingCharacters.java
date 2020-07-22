class Solution {
    public int lengthOfLongestSubstring(String s) {
        HashSet<Character> hashSet = new HashSet<>();
        int l = 0, r = 0, res = 0;

        while (r < s.length()){
            if (!hashSet.contains(s.charAt(r))) {
                hashSet.add(s.charAt(r));
                res = Math.max(res, hashSet.size());
                r += 1;
            }else {
                hashSet.remove(s.charAt(l));
                l += 1;
            }
        }

        return res;
    }
}

/*
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
*/

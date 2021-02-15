class Solution {
    boolean isAlpha(char c) {
        if ('A' <= c && c <= 'Z')
            return true;
        else if ('a' <= c && c <= 'z')
            return true;
        else if ('0' <= c && c <= '9')
            return true;
        return false;
    }

    public boolean isPalindrome(String s) {
        int i = 0;
        int j = s.length() - 1;

        while (i < j) {
            while (!isAlpha(s.charAt(i)) && i < j) i++;
            while (!isAlpha(s.charAt(j)) && i < j) j--;

            if(Character.toLowerCase(s.charAt(i)) != Character.toLowerCase(s.charAt(j))) {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
}

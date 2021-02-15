class Solution {
    public String removeDuplicateLetters(String s) {
        int len = s.length();
        char[] ca = s.toCharArray();
        int[] lastIndex = new int[26];
        for (int i = 0; i < len; i++) {
            lastIndex[ca[i] - 'a'] = i;
        }

        Deque<Character> stack = new ArrayDeque<>();
        boolean[] vis = new boolean[26];

        for (int i = 0; i < len; i++) {
            if (vis[ca[i] - 'a']) {
                continue;
            }
            while (!stack.isEmpty() && stack.peekLast() > ca[i] && lastIndex[stack.peekLast() - 'a'] > i) {
                Character top = stack.removeLast();
                vis[top - 'a'] = false;
            }

            stack.addLast(ca[i]);
            vis[ca[i] - 'a'] = true;
        }
        
        StringBuilder sb = new StringBuilder();
        for (char c : stack) {
            sb.append(c);
        }
        return sb.toString();
    }
}

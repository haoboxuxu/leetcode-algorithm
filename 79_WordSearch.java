class Solution {
    public boolean exist(char[][] board, String word) {
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length; j++) {
                if (word.charAt(0) == board[i][j] && bfs(i, j, 0, board, word)) {
                    return true;
                }
            }
        }
        return false;
    }

    private boolean check(int i, int j, int count, char[][] board, String word) {
        if (i < 0 || i >= board.length || j < 0 || j >= board[0].length || board[i][j] != word.charAt(count)) {
            return false;
        }
        return true;
    }

    private boolean bfs(int i, int j, int count, char[][] board, String word) {
        if (count == word.length()) {
            return true;
        }
        if (!check(i, j, count, board, word)) {
            return false;
        }
        char temp = board[i][j];
        board[i][j] = ' ';
       boolean res = bfs(i-1, j, count+1, board, word) ||
                     bfs(i+1, j, count+1, board, word) ||
                     bfs(i, j+1, count+1, board, word) ||
                     bfs(i, j-1, count+1, board, word);
        board[i][j] = temp;
        return res;
    }
}

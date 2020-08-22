class Solution {
    int n, m;
    public boolean exist(char[][] board, String word) {
        n = board.length;
        m = board[0].length;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word.charAt(0) && bfs(i, j, 0, board, word)) {
                    return true;
                }
            }
        }
        return false;
    }

    private boolean check(int i, int j, int index, char[][] board, String word) {
        if (i < 0 || i >= n || j < 0 || j >= m || board[i][j] != word.charAt(index)) {
            return false;
        }
        return true;
    }

    private boolean bfs(int i, int j, int index, char[][] board, String word) {
        if (index == word.length()) {
            return true;
        }
        if (!check(i, j, index, board, word)) {
            return false;
        }
        char temp = board[i][j];
        board[i][j] = ' ';
        boolean res = bfs(i-1, j, index+1, board, word) ||
                      bfs(i+1, j, index+1, board, word) ||
                      bfs(i, j+1, index+1, board, word) ||
                      bfs(i, j-1, index+1, board, word);
        board[i][j] = temp;
        return res;
    }
}

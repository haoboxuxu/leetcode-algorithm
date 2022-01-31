class Solution {
public:
    int n, m;
    int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0) return;
        n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') dfs(board, i, 0);
            if (board[i][m-1] == 'O') dfs(board, i, m-1);
        }
        for (int i = 0; i < m; i++) {
            if (board[0][i] == 'O') dfs(board, 0, i);
            if (board[n-1][i] == 'O') dfs(board, n-1, i); 
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == '#') board[i][j] = 'O';
                else board[i][j] = 'X';
            }
        }
    }

    void dfs(vector<vector<char>>& board, int x, int y) {
        board[x][y] = '#';
        for (int i = 0; i < 4; i++) {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < n && b >= 0 && b < m && board[a][b] == 'O') dfs(board, a, b);
        }
    }
};
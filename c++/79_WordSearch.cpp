class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        row = (int)board.size();
        col = (int)board[0].size();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
    
private:
    int row, col;
    
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int k) {
        if (i >= row || i < 0 || j >= col || j < 0 || board[i][j] != word[k]) {
            return false;
        }
        if (k == word.length() - 1) return true;
        
        board[i][j] = '\0'; //visited
        
        bool res = dfs(board, word, i+1, j, k+1) ||
                   dfs(board, word, i-1, j, k+1) ||
                   dfs(board, word, i, j+1, k+1) ||
                   dfs(board, word, i, j-1, k+1);
        
        board[i][j] = word[k];
        return res;
    }
};
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool st[9];
        
        //行
        for (int i = 0; i < 9; i++) {
            memset(st, 0, sizeof st);
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int t = board[i][j] - '1';
                    if (st[t]) return false;
                    st[t] = true;
                }
            }
        }
        
        //列
        for (int i = 0; i < 9; i++) {
            memset(st, 0, sizeof st);
            for (int j = 0; j < 9; j++) {
                if (board[j][i] != '.') {
                    int t = board[j][i] - '1';
                    if (st[t]) return false;
                    st[t] = true;
                }
            }
        }
        
        //3x3
        for (int i = 0; i < 9; i+=3) {
            for (int j = 0; j < 9; j+=3) {
                memset(st, 0, sizeof st);
                for (int x = 0; x < 3; x++) {
                    for (int y = 0; y < 3; y++) {
                        if (board[i+x][j+y] != '.') {
                            int t = board[i+x][j+y] - '1';
                            if (st[t]) return false;
                            st[t] = true;
                        }
                    }
                }
            }
        }
        
        return true;
    }
};

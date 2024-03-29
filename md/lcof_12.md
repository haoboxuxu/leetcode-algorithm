# [剑指 Offer 12. 矩阵中的路径](https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof/)

请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一格开始，每一步可以在矩阵中向左、右、上、下移动一格。如果一条路径经过了矩阵的某一格，那么该路径不能再次进入该格子。例如，在下面的3×4的矩阵中包含一条字符串“bfce”的路径（路径中的字母用加粗标出）。

[["a","b","c","e"],
["s","f","c","s"],
["a","d","e","e"]]

但矩阵中不包含字符串“abfb”的路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入这个格子。

 

示例 1：

输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
输出：true
示例 2：

输入：board = [["a","b"],["c","d"]], word = "abcd"
输出：false


提示：

1 <= board.length <= 200
1 <= board[i].length <= 200

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。



```c++
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (dfs(board, word, 0, i, j)) return true;
            }
        }
        return false;
    }
    
    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
    
    bool dfs(vector<vector<char>>& board, string& word, int u, int x, int y) {
        if (board[x][y] != word[u]) return false;
        if (word.size() - 1 == u) return true;
        char c = board[x][y];
        board[x][y] = '.';
        for (int i = 0; i < 4; i++) {
            int a = x + dx[i], b = y + dy[i];
            if (a < 0 || a >= board.size() || b < 0 || b >= board[0].size() || board[a][b] == '.') continue;
            if (dfs(board, word, u+1, a, b)) return true;
        }
        board[x][y] = c;
        return false;
    }
};
```


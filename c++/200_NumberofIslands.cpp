//dfs
class Solution {
public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    res++;
                }
            }
        }
        return res;
    }
    
    void dfs(vector<vector<char>>& grid, int x, int y) {
        grid[x][y] = '0';
        for (int i = 0; i < 4; i++) {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < grid.size() && b >= 0 && b < grid[0].size() && grid[a][b] == '1') {
                dfs(grid, a, b);
            }
        }
    }
};
//bfs
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int res = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    ++res;
                    grid[i][j] = '0';
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    
                    while (!q.empty()) {
                        auto ij = q.front();
                        q.pop();
                        int ii = ij.first, jj = ij.second;
                        if (ii - 1 >= 0 && grid[ii-1][jj] == '1') {
                            q.push({ii-1, jj});
                            grid[ii-1][jj] = '0';
                        }
                        if (ii + 1 < n && grid[ii+1][jj] == '1') {
                            q.push({ii+1, jj});
                            grid[ii+1][jj] = '0';
                        }
                        if (jj - 1 >= 0 && grid[ii][jj-1] == '1') {
                            q.push({ii, jj-1});
                            grid[ii][jj-1] = '0';
                        }
                        if (jj + 1 < m && grid[ii][jj+1] == '1') {
                            q.push({ii, jj+1});
                            grid[ii][jj+1] = '0';
                        }
                    }
                }
            }
        }
        
        return res;
    }
};

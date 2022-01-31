class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> res;
        for (int i = 0; i < n; i++) {
            vector<int> line(i+1);
            line[0] = line[i] = 1;
            for (int j = 1; j < i; j++) {
                line[j] = res[i-1][j-1] + res[i-1][j];
            }
            res.push_back(line);
        }
        return res;
    }
};

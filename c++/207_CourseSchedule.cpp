class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        vector<int> d(n);
        for (auto& edge : edges) {
            int a = edge[1], b = edge[0];
            g[a].push_back(b);
            d[b]++;
        }
        
        queue<int> q;
        for (int i = 0; i < n; i++) if (d[i] == 0) q.push(i);

        int cnt = 0;
        while (q.size()) {
            auto t = q.front();
            q.pop();
            cnt++;
            for (auto i : g[t]) {
                if (--d[i] == 0) q.push(i);
            }
        }

        return cnt == n;
    }
};
class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        vector<int> d(n);
        for (auto& edge : edges) {
            int a = edge[1], b = edge[0];
            g[a].push_back(b);
            d[b]++;
        }
        
        queue<int> q;
        for (int i = 0; i < n; i++) if (d[i] == 0) q.push(i);

        vector<int> res;
        while (q.size()) {
            auto t = q.front();
            q.pop();
            res.push_back(t);
            for (auto i : g[t]) {
                if (--d[i] == 0) q.push(i);
            }
        }

        if (res.size() < n) return {};
        return res;
    }
};

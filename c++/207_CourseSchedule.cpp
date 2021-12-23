class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        vector<int> d(n);
        for (auto e : edges) {
            int a = e[0], b = e[1];
            g[b].push_back(a);
            d[a]++;
        }
        
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (d[i] == 0) q.push(i);
        }
        
        int cnt = 0;
        while (!q.empty()) {
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

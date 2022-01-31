class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        typedef long double LD;
        int res = 0;
        for (auto& p : points) {
            int ss = 0, vs = 0;
            unordered_map<LD, int> mp;
            for (auto q : points) {
                if (p == q)  {
                    ss++;
                } else if (p[0] == q[0]) {
                    vs++;
                } else {
                    LD k = (LD)(q[1] - p[1]) / (q[0] - p[0]);
                    mp[k]++;
                }
            }
            int c = vs;
            for (auto [k, v] : mp) c = max(c, v);
            res = max(res, c + ss);
        }
        return res;
    }
};

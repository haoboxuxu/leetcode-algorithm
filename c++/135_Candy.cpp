class Solution {
public:
    vector<int> f, ratings;
    int n;
    int candy(vector<int>& _ratings) {
        n = _ratings.size();
        ratings = _ratings;
        f.resize(n, -1);

        int res = 0;
        for (int i = 0; i < n; i++) res += dp(i);
        return res;
    }

    int dp(int x) {
        if (f[x] != -1) return f[x];
        f[x] = 1;
        if (x > 0 && ratings[x - 1] < ratings[x]) f[x] = max(f[x], dp(x - 1) + 1);
        if (x + 1 < n && ratings[x + 1] < ratings[x]) f[x] = max(f[x], dp(x + 1) + 1);
        return f[x];
    }
};
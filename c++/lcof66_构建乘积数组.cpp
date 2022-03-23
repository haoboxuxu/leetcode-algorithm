class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int n = a.size();
        vector<int> p(n, 1);
        for (int i = 1; i < n; i++) p[i] = p[i - 1] * a[i - 1];
        for (int i = n - 1, s = 1; i >= 0; i--) {
            p[i] *= s;
            s *= a[i];
        }
        return p;
    }
};

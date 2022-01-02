class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> v;
        v.push_back(1);
        for (int i = 0, j = 0, k = 0; v.size() < n;) {
            int t = min(v[i] * 2, min(v[j] * 3, v[k] * 5));
            v.push_back(t);
            if (v[i] * 2 == t) i++;
            if (v[j] * 3 == t) j++;
            if (v[k] * 5 == t) k++;
        }
        return v.back();
    }
};

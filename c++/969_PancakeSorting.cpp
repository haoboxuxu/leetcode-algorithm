class Solution {
public:
    vector<int> pancakeSort(vector<int>& a) {
        int n = a.size();
        vector<int> res;
        for (int i = n - 1; i >= 0; i--) {
            int k = 0;
            for (int j = 0; j <= i; j++) {
                if (a[j] > a[k]) k = j;
            }
            if (k == i) continue;
            reverse(a.begin(), a.begin() + k + 1);
            res.push_back(k + 1);
            reverse(a.begin(), a.begin() + i + 1);
            res.push_back(i + 1);
        }
        return res;
    }
};

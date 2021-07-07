class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int childNum = (int)g.size();
        int cookiesNum = (int)s.size();
        int res = 0;
        
        for (int i = 0, j = 0; i < childNum && j < cookiesNum; i++, j++) {
            while (j < cookiesNum && g[i] > s[j]) {
                j++;
            }
            if (j < cookiesNum) {
                res += 1;
            }
        }
        
        return res;
    }
};

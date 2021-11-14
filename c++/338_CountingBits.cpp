//sol2
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> f(n+1);
        for (int i = 0; i <= n; i++) {
            f[i] = f[i>>1] + (i&1);
        }
        return f;
    }
};
//sol1
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1);
        for (int i = 0; i <= n; i++) {
            res[i] = count(i);
        }
        return res;
    }
    
    int count(int x) {
        int res = 0;
        while (x > 0) {
            x &= (x-1);
            res++;
        }
        return res;
    }
};

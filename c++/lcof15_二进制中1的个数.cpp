class Solution {
public:
    uint32_t lowbit(uint32_t x) {
        return x & -x;
    }
    int hammingWeight(uint32_t n) {   
        int res = 0;
        while (n) n -= lowbit(n), res++;
        return res;
    }
};
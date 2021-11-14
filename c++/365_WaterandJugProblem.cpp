class Solution {
public:
    bool canMeasureWater(int a, int b, int c) {
        if (c > a + b) return false;
        return !c || c % gcd(a, b) == 0;
    }
    
    int gcd(int a, int b) {
        return b ?  gcd(b, a % b) : a;
    }
};

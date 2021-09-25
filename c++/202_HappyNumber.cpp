class Solution {
public:
    bool isHappy(int n) {
        int slow = n, fast = next(n);
        while (fast != 1 && slow != fast) {
            slow = next(slow);
            fast = next(next(fast));
        }
        return fast == 1;
    }
    
    int next(int n) {
        int res = 0;
        while (n > 0) {
            res += (n%10)*(n%10);
            n /= 10;
        }
        return res;
    }
};

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> set;
        while (n != 1 && !set.count(n)) {
            set.insert(n);
            n = next(n);
        }
        return n == 1;
    }
    
    int next(int n) {
        int res = 0;
        while (n > 0) {
            res += (n%10)*(n%10);
            n /= 10;
        }
        return res;
    }
};

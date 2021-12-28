class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int x = 0, y = 0, n = 0, m = 1;
        for (auto num : nums) n ^= num;
        
        while ((n & m) == 0) m <<= 1;
        
        for (auto num : nums) {
            if (num & m) x ^= num;
            else y ^= num;
        }
        
        return vector<int>{x, y};
    }
};

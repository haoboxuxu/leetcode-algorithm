class Solution {
public:
    int singleNumber(vector<int>& nums) {
        short count[32] = {0};
        for (auto num : nums) {
            for (int j = 0; j < 32; j++) {
                count[j] += num & 1;
                num >>= 1;
            }
        }
        
        int res = 0;
        for (int i = 0; i < 32; i++) {
            res <<= 1;
            res |= count[31-i] % 3;
        }
        return res;
    }
};

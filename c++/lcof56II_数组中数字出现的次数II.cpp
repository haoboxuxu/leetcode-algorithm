class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> mem(32);
        for (auto num : nums) {
            for (int j = 0; j < 32; j++) {
                mem[j] += num & 1;
                num >>= 1;
            }
        }

        int res = 0;
        for (int i = 0; i < 32; i++) {
            res |= (mem[i] % 3 << i);
        }
        return res;
    }
};
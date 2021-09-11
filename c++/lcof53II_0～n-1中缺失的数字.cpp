class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            res ^= nums[i];
            res ^= i;
        }
        res ^= (int)nums.size();
        return res;
    }
};

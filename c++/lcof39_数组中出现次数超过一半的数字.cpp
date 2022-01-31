class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int x = -1;
        int cnt = 0;
        for (auto num : nums) {
            if (num == x) {
                cnt++;
            } else if (--cnt < 0) {
                x = num;
                cnt = 1;
            }
        }
        return x;
    }
};
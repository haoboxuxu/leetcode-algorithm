class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int r = 0, c = 0;
        for (auto x : nums) {
            if (c == 0) {
                r = x, c = 1;
            } else if (r == x) {
                c++;
            } else {
                c--;
            }
        }
        return r;
    }
};
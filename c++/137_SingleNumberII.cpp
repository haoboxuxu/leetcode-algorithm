// sol1
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int n : nums) {
            mp[n]++;
        }
        int res = 0;
        for (auto [n, t] : mp) {
            if (t == 1) {
                res = n;
                break;;
            }
        }
        return res;
    }
};
// sol2
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < 32; i++) {
            int total = 0;
            for (int num : nums) {
                total += ((num >> i) & 1);
            }
            if (total % 3) {
                res |= (1 << i);
            }
        }
        return res;
    }
};

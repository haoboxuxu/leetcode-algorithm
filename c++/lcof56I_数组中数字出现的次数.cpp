class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int sum = 0;
        for (auto num : nums) sum ^= num;
        int k = 0;
        while (!(sum >> k & 1)) k++;
        int x = 0;
        for (auto num : nums) {
            if (num >> k & 1) x ^= num;
        }
        return {x, sum ^ x};
    }
};
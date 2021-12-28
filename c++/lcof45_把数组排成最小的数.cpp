class Solution {
public:
    string minNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int x, int y) {
            string a = to_string(x), b = to_string(y);
            return a + b < b + a;
        });
        
        string res;
        for (auto num: nums) {
            res += to_string(num);
        }
        return res;
    }
};

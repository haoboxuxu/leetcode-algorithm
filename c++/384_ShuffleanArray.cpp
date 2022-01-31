class Solution {
public:
    vector<int> a;

    Solution(vector<int>& nums) {
        a = nums;
    }
    
    vector<int> reset() {
        return a;
    }
    
    vector<int> shuffle() {
        auto b = a;
        int n = b.size();
        for (int i = 0; i < n; i++) {
            swap(b[i], b[i + rand() % (n - i)]);
        }
        return b;
    }
};

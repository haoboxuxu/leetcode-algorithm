class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for (auto num : nums) {
            st.insert(num);
        }
        int res = 0;
        for (auto num : nums) {
            if (!st.count(num-1)) {
                int x = num;
                int curRes = 1;
                
                while (st.count(x+1)) {
                    x += 1;
                    curRes += 1;
                }
                res = max(res, curRes);
            }
        }
        return res;
    }
};

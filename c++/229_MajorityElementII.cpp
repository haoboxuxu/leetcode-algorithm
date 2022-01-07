class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int r1, r2, c1 = 0, c2 = 0;
        for (auto num : nums) {
            if (c1 && num == r1) c1++;
            else if (c2 && num == r2) c2++;
            else if (!c1) r1 = num, c1++;
            else if (!c2) r2 = num, c2++;
            else c1--, c2--;
        }
        
        c1 = 0;
        c2 = 0;
        for (auto num : nums) {
            if (num == r1) c1++;
            else if (num == r2) c2++;
        }
        
        vector<int> res;
        int n = nums.size();
        if (c1 > n / 3) res.push_back(r1);
        if (c2 > n / 3) res.push_back(r2);
        return res;
    }
};

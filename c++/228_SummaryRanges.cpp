class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        for (int i = 0; i < nums.size(); i++) {
            int low = i;
            while (i < nums.size()-1 && nums[i] == nums[i+1] - 1) i++;
            int high = i;
            string s = to_string(nums[low]);
            if (low < high) {
                s.append("->");
                s.append(to_string(nums[high]));
            }
            res.push_back(move(s));
        }
        return res;
    }
};

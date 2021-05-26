class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return {};
        std::sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        
        for (int i = 0; i < intervals.size(); i++) {
            int left = intervals[i][0];
            int right = intervals[i][1];
            if (!res.size() || res.back()[1] < left) {
                res.push_back({left, right});
            } else {
                res.back()[1] = max(res.back()[1], right);
            }
        }
        
        cout << "1" << endl;
        
        return res;
    }
};
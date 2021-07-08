class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
            return a[1] < b[1];
        });
        
        int len = (int)intervals.size();
        int right = intervals[0][1];
        int res = 0;
        
        for (int i = 1; i < len; i++) {
            if (intervals[i][0] < right) {
                res += 1;
            } else {
                right = intervals[i][1];
            }
        }
        
        return res;
    }
};

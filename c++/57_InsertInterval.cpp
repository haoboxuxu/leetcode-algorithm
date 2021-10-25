class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int newLeft = newInterval[0];
        int newRight = newInterval[1];
        bool placed = false;
        vector<vector<int>> res;
        
        for (const auto& interval: intervals) {
            int left = interval[0], right = interval[1];
            if (left > newRight) { //在右侧，不交叉
                if (!placed) {
                    res.push_back({newLeft, newRight});
                    placed = true;
                }
                res.push_back(interval);
            } else if (right < newLeft) { //在左侧，不交叉
                res.push_back(interval);
            } else {
                newLeft = min(left, newLeft);
                newRight = max(right, newRight);
            }
        }
        
        if (!placed) res.push_back({newLeft, newRight});
        
        return res;
    }
};

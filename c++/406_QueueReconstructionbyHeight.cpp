class Solution {
public:
    static bool cmp(const vector<int>& p1, const vector<int>& p2) {
        return p1[0] > p2[0] || (p1[0] == p2[0] && p1[1] < p2[1]);
    }
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        
        for (const auto &p : people) {
            cout << p[0] << "," << p[1] << endl;
        }
        
        vector<vector<int>> res;
        for (const auto &p : people) {
            res.insert(res.begin() + p[1], p);
        }
        
        return res;
    }
};

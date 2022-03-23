class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (auto s : strs) {
            string t = s;
            sort(s.begin(), s.end());
            mp[s].push_back(t);
        }
        vector<vector<string>> res;
        for (auto i : mp) {
            res.push_back(i.second);
        }
        return res;
    }
};
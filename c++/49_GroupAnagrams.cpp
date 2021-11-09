//sol1
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (auto& s : strs) {
            string k = s;
            sort(k.begin(), k.end());
            mp[k].emplace_back(s);
        }
        
        vector<vector<string>> res;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            res.push_back(it->second);
        }
        
        return res;
    }
};
//sol2



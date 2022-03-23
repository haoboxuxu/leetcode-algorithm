class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> mp;
        for (int i = 0; i + 10 <= s.size(); i++) {
            mp[s.substr(i, 10)]++;
        }
        vector<string> res;
        for (auto [k, v] :  mp) {
            if (v > 1) res.push_back(k);
        }
        return res;
    }
};
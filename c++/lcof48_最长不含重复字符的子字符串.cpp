class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int res = 0;
        for (int i = 0, j = 0; j < s.size(); j++) {
            mp[s[j]]++;
            while (mp[s[j]] > 1) mp[s[i++]]--;
            res = max(res, j - i + 1);
        }
        return res;
    }
};
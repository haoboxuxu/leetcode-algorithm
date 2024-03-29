class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int res = 0;
        for (int i = 0, j = 0; i < s.size(); i++) {
            mp[s[i]]++;
            while (mp[s[i]] > 1) mp[s[j++]]--;
            res = max(res, i - j + 1);
        }
        return res;
    }
};
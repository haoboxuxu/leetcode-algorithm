class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = (int)s.size();
        if (len == 0) return 0;

        unordered_map<char, int> map;
        
        int max_len = 0, current_len = 0, start_index = 0;
        
        for (int i = 0; i < len; i++) {
            if (map.find(s[i]) == map.end()) {
                current_len++;
                map[s[i]] = i;
            } else {
                if (current_len > max_len) {
                    max_len = current_len;
                }
                start_index = max(map[s[i]], start_index);
                current_len = i - start_index;
                map[s[i]] = i;
            }
            if (current_len > max_len) max_len = current_len;
        }
        
        return max_len;
    }
};

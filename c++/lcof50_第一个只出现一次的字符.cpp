class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<char, int> pos;
        queue<pair<char, int>> q;
        int len = (int)s.length();
        for (int i = 0; i < len; i++) {
            if (!pos.count(s[i])) {
                pos[s[i]] = i;
                q.emplace(s[i], i);
            } else {
                pos[s[i]] = -1;
                while (!q.empty() && pos[q.front().first] == -1) {
                    q.pop();
                }
            }
        }
        return q.empty() ? ' ' : q.front().first;
    }
};

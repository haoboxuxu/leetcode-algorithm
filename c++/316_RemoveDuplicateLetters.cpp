class Solution {
public:
    string removeDuplicateLetters(string s) {
        string stk;
        unordered_map<char, bool> ins;
        unordered_map<char, int> last;
        for (int i = 0; i < s.length(); i++) last[s[i]] = i;
        
        for (int i = 0; i < s.length(); i++) {
            if (ins[s[i]]) continue;
            while (stk.size() && stk.back() > s[i] && last[stk.back()] > i) {
                ins[stk.back()] = false;
                stk.pop_back();
            }
            stk += s[i];
            ins[s[i]] = true;
        }
        
        return stk;
    }
};

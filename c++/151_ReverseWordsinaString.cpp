// sol1 O1
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        
        int len = s.size();
        int idx = 0;
        for (int start = 0; start < len; start++) {
            if (s[start] != ' ' ) {
                if (idx != 0) s[idx++] = ' ';
                
                int end = start;
                while (end < len && s[end] != ' ') s[idx++] = s[end++];
                
                reverse(s.begin()+idx-(end-start), s.begin()+idx);
                
                start = end;
            }
        }
        s.erase(s.begin() + idx, s.end());
        return s;
    }
};
// sol2 On
class Solution {
public:
    string reverseWords(string s) {
        int left = 0, right = s.size() - 1;
        while (left <= right && s[left] == ' ' ) left++;
        while (left <= right && s[right] == ' ' ) right--;
        
        deque<string> dq;
        string word;
        
        while (left <= right) {
            char c = s[left];
            if (word.size() && c == ' ') {
                dq.push_front(move(word));
                word = "";
            }
            if (c != ' ' ) {
                word += c;
            }
            left++;
        }
        dq.push_front(move(word));
        
        string res;
        
        while (!dq.empty()) {
            res += dq.front();
            dq.pop_front();
            if (!dq.empty()) res += ' ';
        }
        
        return res;
    }
};

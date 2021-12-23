// o(1)
class Solution {
public:
    string reverseWords(string s) {
        int len = s.length();
        int i = 0;
        
        while (i < len) {
            int start = i;
            while (i < len && s[i] != ' ') i++;
            int left = start, right = i - 1;
            while (left < right) {
                swap(s[left], s[right]);
                left++, right--;
            }
            while (i < len && s[i] == ' ') {
                i++;
            }
        }
        
        return s;
    }
};
// o(n)
class Solution {
public:
    string reverseWords(string s) {
        string res;
        int len = s.length();
        
        int i = 0;
        
        while (i < len) {
            int start = i;
            while (i < len && s[i] != ' ') i++;
            for (int p = start; p< i; p++) res.push_back(s[start + i - 1 - p]);
            while (i < len && s[i] == ' ') {
                i++;
                res.push_back(' ');
            }
        }
        
        return res;
    }
};

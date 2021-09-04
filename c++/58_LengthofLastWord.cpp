class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = (int)s.size();
        int tail = len-1;
        bool flag = false;
        for (int i = len; i >= 0; i--) {
            if (s[i] != ' ' && flag == false) {
                tail = i;
                flag = true;
            }
            if (flag == true &&  s[i] == ' ') {
                return (tail-i);
            }
        }
        
        return tail+1;
    }
};

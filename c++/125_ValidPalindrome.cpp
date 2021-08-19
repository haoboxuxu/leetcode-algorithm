//sol1
class Solution {
public:
    bool isPalindrome(string s) {
        string ss;
        for (char c : s) {
            if (isalnum(c)) {
                ss += tolower(c);
            }
        }
        string ss_rev(ss.rbegin(), ss.rend());
        return  ss == ss_rev;
    }
};
//sol2
class Solution {
public:
    bool isPalindrome(string s) {
        string ss;
        for (char c : s) {
            if (isalnum(c)) {
                ss += tolower(c);
            }
        }
        int n = (int)ss.size();
        int left = 0, right = n - 1;
        while (left < right) {
            if (ss[left] != ss[right]) return false;
            left++;
            right--;
        }
        
        return true;
    }
};
//sol3
class Solution {
public:
    bool isPalindrome(string s) {
        int n = (int)s.size();
        int left = 0, right = n - 1;
        while (left < right) {
            while (left < right && !isalnum(s[left])) {
                left++;
            }
            while (left < right && !isalnum(s[right])) {
                right--;
            }
            if (left < right) {
                if (tolower(s[left]) != tolower(s[right])) {
                    return false;
                }
                left++;
                right--;
            }
        }
        return true;
    }
};

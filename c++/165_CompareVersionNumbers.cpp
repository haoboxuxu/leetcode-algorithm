class Solution {
public:
    int compareVersion(string version1, string version2) {
        int len1 = version1.length(), len2 = version2.length();
        int i = 0, j = 0;
        while (i < len1 || j < len2) {
            int x = 0;
            for (; i < len1 && version1[i] != '.'; i++) {
                x = x*10 + version1[i] - '0';
            }
            i++;
            int y = 0;
            for (; j < len2 && version2[j] != '.'; j++) {
                y = y*10 + version2[j] - '0';
            }
            j++;
            
            if (x != y) {
                return x > y ? 1 : -1;
            }
        }
        return 0;
    }
};

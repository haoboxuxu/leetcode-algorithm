class Solution {
public:
    int m[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dayOfYear(string date) {
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));
        
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) m[2] += 1;
        
        int res = day;
        for (int i = 1; i <= month; i++) {
            res += m[i];
        }
        return res;
    }
};

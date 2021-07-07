// sol1
class Solution {
public:
    int candy(vector<int>& ratings) {
        int len = (int)ratings.size();
        vector<int> left(len);
        for (int i = 0; i < len; i++) {
            if (i > 0 && ratings[i] > ratings[i-1]) {
                left[i] = left[i-1] + 1;
            } else {
                left[i] = 1;
            }
        }
        
        int right = 0, res = 0;
        for (int i = len-1; i >= 0; i--) {
            if (i < len-1 && ratings[i] > ratings[i+1]) {
                right++;
            } else {
                right = 1;
            }
            res += max(left[i], right);
        }
        
        return res;
    }
};
// sol2



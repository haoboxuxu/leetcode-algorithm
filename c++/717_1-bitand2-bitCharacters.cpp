class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        int i = 0;
        for (; i < n - 1;) {
            if (bits[i]) i += 2;
            else i += 1;
        }
        return i == n - 1;
    }
};

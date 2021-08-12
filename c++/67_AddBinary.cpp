class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        int n = (int)max(a.size(), b.size());
        int carry = 0;
        
        for (int i = 0; i < n; i++) {
            if (i < a.size() && a.at(i) == '1') {
                carry += 1;
            }
            if (i < b.size() && b.at(i) == '1') {
                carry += 1;
            }
            res.push_back((carry%2) ? '1' : '0');
            carry /= 2;
        }
        
        if (carry) res.push_back('1');
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};

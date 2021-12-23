class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.size(), len2 = num2.size();
        vector<int> A, B;
        for (int i = len1-1; i >= 0; i--) A.push_back(num1[i] - '0');
        for (int i = len2-1; i >= 0; i--) B.push_back(num2[i] - '0');
        
        vector<int> C(len1+len2);
        
        for (int i = 0; i < len1; i++) {
            for (int j = 0; j < len2; j++) {
                C[i+j] += A[i] * B[j];
            }
        }
        
        for (int i = 0, t = 0; i < C.size(); i++) {
            t += C[i];
            C[i] = t % 10;
            t /= 10;
        }
        
        int k = C.size() - 1;
        while (k > 0 && !C[k]) k--;
        
        string res;
        while (k >= 0) res += C[k--] + '0';
        return res;
    }
};

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        auto midit = nums.begin() + n / 2;
        nth_element(nums.begin(), midit, nums.end());
        int mid = *midit;

        #define A(i) nums[(i * 2 + 1) % (n | 1)]
        for (int i = 0, j = 0, k = n - 1; i <= k;) {
            if (A(i) > mid) swap(A(i ++ ), A(j ++ ));
            else if (A(i) < mid) swap(A(i), A(k -- ));
            else i ++ ;
        }
    }
};

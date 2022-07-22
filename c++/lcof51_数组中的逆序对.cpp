class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return merge(nums, 0, nums.size() - 1);
    }

    int merge(vector<int>& nums, int l, int r) {
        if (l >= r) return 0;
        int mid = l + r >> 1;
        int res = merge(nums, l, mid) + merge(nums, mid + 1, r);
        int i = l, j = mid + 1;
        vector<int> tmp;
        while (i <= mid && j <= r) {
            if (nums[i] <= nums[j]) {
                tmp.push_back(nums[i++]);
            } else {
                tmp.push_back(nums[j++]);
                res += mid - i + 1;
            }
        }
        while (i <= mid) tmp.push_back(nums[i++]);
        while (j <= r) tmp.push_back(nums[j++]);
        int k = l;
        for (auto x : tmp) nums[k++] = x;
        return res;
    }
};
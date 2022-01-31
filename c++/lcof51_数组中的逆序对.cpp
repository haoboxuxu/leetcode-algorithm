class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return merge(nums, 0, nums.size() - 1);
    }
    
    int merge(vector<int>& nums, int l, int r) {
        if (l >= r) return 0;
        
        int mid = l + r >> 1;
        int res = merge(nums, l, mid) + merge(nums, mid+1, r);
        
        vector<int> tmp;
        int i = l, j = mid + 1;
        while (i <= mid && j <= r) {
            if (nums[i] > nums[j]) {
                tmp.push_back(nums[i++]);
                res += r - j + 1;
            } else {
                tmp.push_back(nums[j++]);
            }
        }
        
        while (i <= mid) tmp.push_back(nums[i++]);
        while (j <= r) tmp.push_back(nums[j++]);
        
        int k = l;
        for (auto t : tmp) nums[k++] = t;
        
        return res;
    }
};

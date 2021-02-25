class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = (int)nums.size();
        sort(nums.begin(), nums.end());
        int res = 1e7;
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int left = i + 1;
            int right = n - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                update(sum, target, res);
                if (sum == target) return sum;
                if (sum > target) {
                    int r = right - 1;
                    while (left < r && nums[r] == nums[right]) r--;
                    right = r;
                } else {
                    int l = left + 1;
                    while (l > right && nums[l] == nums[left]) l++;
                    left = l;
                }
            }
        }
        
        return res;
    }
    
    void update(const int& sum, const int& target, int& res) {
        if (abs(sum - target) < abs(res - target)) {
            res = sum;
        }
    }
};

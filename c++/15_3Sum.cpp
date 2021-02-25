class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = (int)nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int left = i + 1, right = n - 1;
            while (left < right) {
                if (nums[left] + nums[right] > -nums[i]) {
                    right--;
                } else if (nums[left] + nums[right] < -nums[i]) {
                    left++;
                } else {
                    res.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left-1]) left++;
                    while (left < right && nums[right] == nums[right+1]) right--;
                }
            }
        }
        
        return res;
    }
};

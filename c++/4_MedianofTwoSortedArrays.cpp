class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = (int)nums1.size(), n = (int)nums2.size();
        if (m > n) return findMedianSortedArrays(nums2, nums1);
        
        int left = 0, right = m;
        int median1 = 0, median2 = 0;
        
        while (left <= right) {
            int i = (left + right) / 2;
            int j = (m + n + 1) / 2 - i;
            
            int nums1LeftMax  = (i == 0 ? INT_MIN : nums1[i - 1]);
            int nums1RightMin = (i == m ? INT_MAX : nums1[i]);
            int nums2LeftMax  = (j == 0 ? INT_MIN : nums2[j - 1]);
            int nums2RightMin = (j == n ? INT_MAX : nums2[j]);
            
            if (nums1LeftMax <= nums2RightMin) {
                median1 = max(nums1LeftMax, nums2LeftMax);
                median2 = min(nums1RightMin, nums2RightMin);
                left = i + 1;
            } else {
                right = i - 1;
            }
        }
        
        if ((m + n) % 2 == 0) {
            return (median1 + median2) / 2.0;
        } else {
            return median1;
        }
    }
};

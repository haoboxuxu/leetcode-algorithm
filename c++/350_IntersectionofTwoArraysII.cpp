//sol1
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int len1 = (int)nums1.size(), len2 = (int)nums2.size();
        int p1 = 0, p2 = 0;
        vector<int> res;
        while (p1 < len1 && p2 < len2) {
            int num1 = nums1[p1], num2 = nums2[p2];
            if (num1 == num2) {
                res.push_back(num1);
                p1++, p2++;
            } else if (num1 < num2) {
                p1++;
            } else {
                p2++;
            }
        }
        return res;
    }
};
//sol2
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return intersect(nums2, nums1);
        unordered_map<int, int> mp;
        for (int num : nums1) mp[num]++;
        vector<int> res;
        
        for (int num : nums2) {
            if (mp.count(num)) {
                res.push_back(num);
                mp[num]--;
                if (mp[num] == 0) mp.erase(num);
            }
        }
        
        return res;
    }
};

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s;
        vector<int> res;
        for (auto num : nums1) s.insert(num);
        for (auto num : nums2) {
            if (s.count(num)) {
                res.push_back(num);
                s.erase(num);
            }
        }
        return res;
    }
};
class Solution {
public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        vector<int> res;
        int i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i] == b[j]) {
                if (res.empty() || a[i] != res.back()) res.push_back(a[i]);
                i++, j++;
            } else if (a[i] < b[j]) {
                i++;
            } else {
                j++;
            }
        }
        return res;
    }
};
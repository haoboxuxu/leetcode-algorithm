class Solution {
public:
    int k;
    multiset<int> left, right;

    double getMedium() {
        if (k % 2) return *right.begin();
        return ((double)*left.rbegin() + *right.begin()) / 2;
    }

    vector<double> medianSlidingWindow(vector<int>& nums, int _k) {
        k = _k;
        for (int i = 0; i < k; i++) {
            right.insert(nums[i]);
        }
        for (int i = 0; i < k / 2; i++) {
            left.insert(*right.begin());
            right.erase(right.begin());
        }

        vector<double> res;
        res.push_back(getMedium());
        
        for (int i = k; i < nums.size(); i++) {
            int x = nums[i], y = nums[i - k];

            if (x >= *right.begin()) right.insert(x);
            else left.insert(x);
            
            if (y >= *right.begin()) right.erase(right.find(y));
            else left.erase(left.find(y));

            while (left.size() > right.size()) {
                right.insert(*left.rbegin());
                left.erase(left.find(*left.rbegin()));
            }

            while (right.size() > left.size() + 1) {
                left.insert(*right.begin());
                right.erase(right.begin());
            }

            res.push_back(getMedium());
        }

        return res;
    }
};

// dp
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int len = (int)height.size();
        if (len == 0) return 0;
        vector<int> left_max(len), right_max(len);
        left_max[0] = height[0];
        for (int i = 1; i < len; i++) {
            left_max[i] = max(height[i], left_max[i-1]);
        }
        right_max[len - 1] = height[len - 1];
        for (int i = len - 2; i >= 0; i--) {
            right_max[i] = max(height[i], right_max[i+1]);
        }
        for (int i = 0; i < len; i++) {
            res += min(left_max[i], right_max[i]) - height[i];
        }
        return res;
    }
};
// stack
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        stack<int> stk;
        stk.push(0);
        for (int i = 1; i < height.size(); i++) {
            if (height[i] < height[stk.top()]) {
                stk.push(i);
            } else if (height[i] == height[stk.top()]) {
                stk.pop();
                stk.push(i);
            } else {
                while (!stk.empty() && height[i] > height[stk.top()]) {
                    int mid = stk.top();
                    stk.pop();
                    if (!stk.empty()) {
                        int h = min(height[stk.top()], height[i]) - height[mid];
                        int w = i - stk.top() - 1;
                        res += h * w;
                    }
                }
                stk.push(i);
            }
        }
        return res;
    }
};
// two-pointers
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0, len = (int)height.size();
        if (len == 0) return 0;
        int left_max = 0, right_max = 0;
        int left = 0, right = len - 1;
        while (left < right) {
            if (height[left] < height[right]) {
                left_max = max(height[left], left_max);
                res += left_max - height[left];
                left++;
            } else {
                right_max = max(height[right], right_max);
                res += right_max - height[right];
                right--;
            }
        }
        return res;
    }
};
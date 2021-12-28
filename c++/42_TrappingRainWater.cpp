// dp
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int n = height.size();
        vector<int> left_max(n), right_max(n);
        
        left_max[0] = height[0];
        for (int i = 1; i < n; i++) left_max[i] = max(left_max[i-1], height[i]);
        
        right_max[n-1] = height[n-1];
        for (int i = n-2; i >= 0; i--) right_max[i] = max(right_max[i+1], height[i]);
        
        for (int i = 0; i < n; i++) {
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
        int res = 0;
        int n = height.size();
        int left_max = 0, right_max = 0;
        int i = 0, j = n - 1;
        while (i < j) {
            if (height[i] < height[j]) {
                left_max = max(height[i], left_max);
                res += left_max - height[i];
                i++;
            } else {
                right_max = max(height[j], right_max);
                res += right_max - height[j];
                j--;
            }
        }
        return res;
    }
};

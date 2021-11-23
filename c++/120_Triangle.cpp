//sol3
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = (int)triangle.size();
        vector<int> dp(triangle.back());
        
        for (int i = n-2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                dp[j] = min(dp[j], dp[j+1]) + triangle[i][j];
            }
        }
        return dp[0];
    }
};
//sol1
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = (int)triangle.size();
        vector<vector<int>> dp(n, vector<int>(n));
        dp[0][0] = triangle[0][0];
        
        for (int i = 1; i < n; i++) {
            dp[i][0] = dp[i-1][0] + triangle[i][0];
            for (int j = 1; j < i; j++) {
                dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
            }
            dp[i][i] = dp[i-1][i-1] + triangle[i][i];
        }
        
        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};
//sol2
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = (int)triangle.size();
        vector<int> dp(n);
        dp[0] = triangle[0][0];
        
        for (int i = 1; i < n; i++) {
            dp[i] = dp[i-1] + triangle[i][i];
            for (int j = i - 1; j > 0; j--) {
                dp[j] = min(dp[j-1], dp[j]) + triangle[i][j];
            }
            dp[0] += triangle[i][0];
        }
        
        return *min_element(dp.begin(), dp.end());
    }
};

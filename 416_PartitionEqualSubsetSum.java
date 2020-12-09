//fast
class Solution {
    public boolean canPartition(int[] nums) {
        int len = nums.length;
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        
        if ((sum & 1) == 1) {
            return false;
        }

        int sub = sum / 2;

        boolean[] dp = new boolean[sub+1];

        dp[0] = true;
        if (nums[0] <= sub) {
            dp[nums[0]] = true;
        }

        for (int i = 1; i < len; i++) {
            for (int j = sub; j >= 0 && nums[i] <= j; j--) {
                dp[j] = dp[j] || dp[j-nums[i]];
            }

            if (dp[sub]) return true;
        }

        return dp[sub];
    }
}

//slow1
class Solution {
    public boolean canPartition(int[] nums) {
        int len = nums.length;
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }

        //奇数
        if ((sum & 1) == 1) {
            return false;
        }

        int sub = sum / 2;

        //dp[i][j] [0, i]区间内和为j
        boolean[][] dp = new boolean[len][sub+1];

        if (nums[0] <= sub) {
            dp[0][nums[0]] = true;
        }

        for (int i = 1; i < len; i++) {
            for (int j = 0; j <= sub; j++) {
                dp[i][j] = dp[i-1][j];

                if (nums[i] == j) {
                    dp[i][j] = true;
                    continue;
                }
                
                if (nums[i] < j) {
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]];
                }
            }
        }
        
        return dp[len-1][sub]; 
    }
}

//slow2
class Solution {
    public boolean canPartition(int[] nums) {
        int len = nums.length;
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }

        //奇数
        if ((sum & 1) == 1) {
            return false;
        }

        int sub = sum / 2;

        //dp[i][j] [0, i]区间内和为j
        boolean[][] dp = new boolean[len][sub+1];

        dp[0][0] = true;
        if (nums[0] <= sub) {
            dp[0][nums[0]] = true;
        }

        for (int i = 1; i < len; i++) {
            for (int j = 0; j <= sub; j++) {
                dp[i][j] = dp[i-1][j];

                if (nums[i] <= j) {
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]];
                }
            }

            if (dp[i][sub]) return true;
        }

        return dp[len-1][sub];
    }
}

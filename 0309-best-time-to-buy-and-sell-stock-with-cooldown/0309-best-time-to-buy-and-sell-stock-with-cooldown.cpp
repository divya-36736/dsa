class Solution {
public:
    int solve(int i, int j, vector<int>& prices, vector<vector<int>>& dp) {
        int n = prices.size();
        if (i >= n)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        if (j == 0) {
            int buy = -prices[i] + solve(i + 1, 1, prices, dp);
            int skip = solve(i + 1, 0, prices, dp);
            return dp[i][j] = max(buy, skip);
        } else {
            int sell = prices[i] + solve(i + 2, 0, prices, dp);
            int skip = solve(i + 1, 1, prices, dp);
            return dp[i][j] = max(sell, skip);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));
        // return solve(0, 0, prices, dp);
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j <= 1; j++) {
                if (j == 0) {
                    int buy = -prices[i] + dp[i+1][1];
                    int skip = dp[i+1][0];
                    dp[i][j] = max(buy, skip);
                } else {
                    int sell = prices[i] + dp[i+2][0];
                    int skip = dp[i+1][1];
                    dp[i][j] = max(sell, skip);
                }
            }
        }
        return dp[0][0];
    }
};
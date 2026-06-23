class Solution {
public:
    int solve(int i, int hold, int trans, vector<int>& prices,
              vector<vector<vector<int>>>& dp) {
        if (i == prices.size())
            return 0;
        if (trans == 0)
            return 0;

        if (dp[i][hold][trans] != -1)
            return dp[i][hold][trans];

        if (hold == 0) {
            int buy = -prices[i] + solve(i + 1, 1, trans, prices, dp);
            int skip = solve(i + 1, 0, trans, prices, dp);
            return dp[i][hold][trans] = max(buy, skip);
        } else {
            int sell = prices[i] + solve(i + 1, 0, trans - 1, prices, dp);
            int skip = solve(i + 1, 1, trans, prices, dp);
            return dp[i][hold][trans] = max(sell, skip);
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));
        // return solve(0, 0, 2, prices, dp);
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j <= 1; j++) {
                for (int t = 1; t <= k; t++) {
                    if (j == 0) {
                        int buy = -prices[i] + dp[i + 1][1][t];
                        int skip = dp[i + 1][0][t];
                        dp[i][j][t] = max(buy, skip);
                    } else {
                        int sell = prices[i] + dp[i + 1][0][t-1];
                        int skip = dp[i + 1][1][t];
                        dp[i][j][t] = max(sell, skip);
                    }
                }
            }
        }
        return dp[0][0][k];
    }
};
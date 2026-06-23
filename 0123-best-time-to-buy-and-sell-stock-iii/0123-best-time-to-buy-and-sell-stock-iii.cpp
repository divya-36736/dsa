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
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<vector<int>>> dp(
        //     n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        vector<vector<int>>prev(2, vector<int>(3, 0));
        vector<vector<int>>curr(2, vector<int>(3, 0));

        // return solve(0, 0, 2, prices, dp);
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j <= 1; j++) {
                for (int k = 1; k <= 2; k++) {
                    if (j == 0) {
                        int buy = -prices[i] + prev[1][k];
                        int skip = prev[0][k];
                        curr[j][k] = max(buy, skip);
                    } else {
                        int sell = prices[i] + prev[0][k-1];
                        int skip = prev[1][k];
                        curr[j][k] = max(sell, skip);
                    }
                }
            }
            prev = curr;
        }
        return prev[0][2];
    }
};
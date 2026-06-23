class Solution {
public:
    int profit(int day, int hold, vector<int>& prices,
               vector<vector<int>>& dp) {
        if (day == prices.size())
            return 0;
        if (dp[day][hold] != -1)
            return dp[day][hold];

        if (hold == 0) {
            // buy or skip
            int buy = -prices[day] + profit(day + 1, 1, prices, dp);
            int skip = profit(day + 1, 0, prices, dp);
            return dp[day][hold] = max(buy, skip);
        } else {
            int sell = prices[day] + profit(day + 1, 0, prices, dp);
            int skip = profit(day + 1, 1, prices, dp);
            return dp[day][hold] = max(sell, skip);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        // return profit(0, 0, prices, dp);
        dp[n][0] = 0;
        dp[n][1] = 0;
        for (int i = n-1; i >=0; i--) {
            for (int j = 0; j <= 1; j++) {
                if (j == 0) {
                    // buy or skip
                    int buy = -prices[i] +dp[i+1][1];
                    int skip = dp[i+1][0];
                    dp[i][j] = max(buy, skip);
                } else {
                    int sell = prices[i] +dp[i+1][0];
                    int skip = dp[i+1][1];
                    dp[i][j] = max(sell, skip);
                }
            }
        }
        return dp[0][0];
    }
};
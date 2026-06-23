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
        //vector<vector<int>> dp(n+1, vector<int>(2, 0));
        // return profit(0, 0, prices, dp);
        vector<int>prev(2, 0), curr(2, 0);
        prev[0] = 0;
        prev[1] = 0;
        for (int i = n-1; i >=0; i--) {
            for (int j = 0; j <= 1; j++) {
                if (j == 0) {
                    // buy or skip
                    int buy = -prices[i] + prev[1];
                    int skip = prev[0];
                    curr[j] = max(buy, skip);
                } else {
                    int sell = prices[i] + prev[0];
                    int skip = prev[1];
                    curr[j] = max(sell, skip);
                }
            }
            prev = curr;
        }
        return prev[0];
    }
};
class Solution {
public:
    int profit(int day, int hold, vector<int>&prices, vector<vector<int>>&dp){
        if(day == prices.size()) return 0;
        if(dp[day][hold] != -1) return dp[day][hold];

        if(hold == 0){
            //buy or skip
            int buy = -prices[day]+profit(day+1, 1, prices, dp);
            int skip = profit(day+1, 0, prices, dp);
            return dp[day][hold] = max(buy, skip);
        }
        else{
            int sell = prices[day]+profit(day+1, 0, prices, dp);
            int skip = profit(day+1, 1, prices, dp);
            return dp[day][hold] = max(sell, skip);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n, vector<int>(2, -1));
        return profit(0, 0, prices, dp);
    }
};
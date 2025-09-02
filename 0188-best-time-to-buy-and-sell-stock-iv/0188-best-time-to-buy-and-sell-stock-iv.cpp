class Solution {
public:
    int solve(int i, int hold, int trans, vector<int>& prices,vector<vector<vector<int>>>&dp) {
        int n = prices.size();
        if (i == n || trans == 0) return 0;

        if(dp[i][hold][trans] != -1) return dp[i][hold][trans];

        if (hold == 0) { 
            int buy = -prices[i] + solve(i+1, 1, trans, prices, dp);
            int skip = solve(i+1, 0, trans, prices, dp);  // fix here
            return dp[i][hold][trans] = max(buy, skip);
        } else {
            int sell = prices[i] + solve(i+1, 0, trans-1, prices, dp);
            int skip = solve(i+1, 1, trans, prices, dp);
            return dp[i][hold][trans] = max(sell, skip);
        }
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(2, vector<int>(k+1,-1)));
        return solve(0, 0, k, prices, dp);
    }
};

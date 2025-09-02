class Solution {
public:
    int solve(int i, int hold,int fee, vector<int>&prices, vector<vector<int>>&dp){
        int n = prices.size();
        if(i == n)return 0;
        //
        if(dp[i][hold] != -1)return dp[i][hold];

        if(hold==0){
            //buy skip
            int buy = -prices[i]+solve(i+1, 1,fee, prices, dp);
            int skip = solve(i+1, 0,fee, prices, dp);
            return dp[i][hold] = max(buy, skip);
        }else{
            int sell = prices[i]+solve(i+1, 0,fee, prices, dp);
            int skip = solve(i+1, 1,fee, prices, dp);
            return dp[i][hold] = max(sell-fee, skip);
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>>dp(n, vector<int>(2,-1));
        return solve(0, 0, fee, prices, dp);
    }
};
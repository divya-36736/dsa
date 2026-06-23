class Solution {
public:
    int solve(int i, int hold,int fee, vector<int>&prices){
        int n = prices.size();
        if(i == n)return 0;
        //
        if(hold==0){
            //buy skip
            int buy = -prices[i]+solve(i+1, 1,fee, prices);
            int skip = solve(i+1, 0,fee, prices);
            return max(buy, skip);
        }else{
            int sell = prices[i]+solve(i+1, 0,fee, prices);
            int skip = solve(i+1, 1,fee, prices);
            return max(sell-fee, skip);
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        //return solve(0, 0, fee, prices);
        vector<vector<int>>dp(n+1, vector<int>(2, 0));
        for(int i = n-1; i>=0; i--){
            for(int j = 0; j<=1; j++){
                if(j == 0){
                    int buy = -prices[i]+dp[i+1][1];
                    int skip = dp[i+1][0];
                    dp[i][j] = max(buy, skip);
                }else{
                    int sell = prices[i]+dp[i+1][0];
                    int skip = dp[i+1][1];
                    dp[i][j] = max(sell-fee, skip);
                }
            }
        }
        return dp[0][0];
    }
};
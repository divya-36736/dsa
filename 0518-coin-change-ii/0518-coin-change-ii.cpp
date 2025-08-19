class Solution {
public:
    int ways(int i, int amount, vector<int>& coins, vector<vector<int>>&dp){
        int n = coins.size();
        if(i == 0){
            return amount % coins[i] == 0;
        }
        if(dp[i][amount] != -1) return dp[i][amount];
        //nottkae
        int nottake = 0+ways(i-1, amount, coins, dp);
        //take
        int take = 0;
        if(coins[i]<=amount){
            take =  ways(i, amount-coins[i], coins, dp);
        }
        return dp[i][amount] = take+nottake;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, -1));
        return ways(n-1, amount, coins, dp);
    }
};
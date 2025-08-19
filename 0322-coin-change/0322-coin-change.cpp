class Solution {
public:
    int minimum(int i, int amount, vector<int>& coins, vector<vector<int>>&dp){
        int n = coins.size();
        if(i == 0){
            if(amount % coins[i] == 0){
                return amount/coins[i];
            }
            else return 1e9;
        }
        if(dp[i][amount] != -1) return dp[i][amount];
        //nottkae
        int nottake = 0+minimum(i-1, amount, coins, dp);
        //take
        int take = INT_MAX;
        if(coins[i]<=amount){
            take = 1+ minimum(i, amount-coins[i], coins, dp);
        }
        return dp[i][amount] = min(take, nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, -1));
        int ans = minimum(n-1, amount, coins, dp);
        if(ans>= 1e9) return -1;
        return ans;
    }
};
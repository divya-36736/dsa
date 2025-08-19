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
        // vector<vector<int>>dp(n, vector<int>(amount+1, -1));
        // int ans = minimum(n-1, amount, coins, dp);
        // if(ans>= 1e9) return -1;
        // return ans;

        //tabulation
        //make vector same size
        vector<vector<int>>dp(n, vector<int>(amount+1, 0));
        //base case
        //target ki kisi bhi value ke liye 
        //if (target%coins[0] == 0) hai toh 
        //dp[0][i] = i / arr[0]; else dp[0][i] = 1e9
        for(int i = 0; i<=amount; i++){
            if(i%coins[0] == 0){
                dp[0][i] = i/coins[0];
            }
            else dp[0][i] = 1e9;
        }
        //for loop
        for(int i = 1; i<n; i++){
            for(int target = 0; target<=amount; target++){
                int nottake = 0+dp[i-1][target];
                //take
                int take = 1e9;
                if(coins[i]<=target){
                take = 1+ dp[i][target-coins[i]];
                } 
                dp[i][target] = min(take, nottake);
            }
            
        }
        int ans = dp[n-1][amount];
            if(ans == 1e9){
                return -1;
            }
            return ans;
    }
};
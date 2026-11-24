class Solution {
public:
    int solve(int amount, vector<int>& coins, vector<int>& dp) {

        if (amount == 0)
            return 0;

        if (amount < 0)
            return INT_MAX;

        if (dp[amount] != -1)
            return dp[amount];

        int mini = INT_MAX;

        for (int coin : coins) {

            int result = solve(amount - coin, coins, dp);

            if (result != INT_MAX) {
                mini = min(mini, 1 + result);
            }
        }

        return dp[amount] = mini;
    }

    int coinChange(vector<int>& coins, int amount) {

        vector<int> dp(amount + 1, -1);

        int ans = solve(amount, coins, dp);

        return ans == INT_MAX ? -1 : ans;
    }
};
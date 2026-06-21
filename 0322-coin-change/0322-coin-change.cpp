class Solution {
public:
    int mini(int i, int amount, vector<int>& coins) {
        if (i == 0) {
            if (amount % coins[i] == 0)
                return amount / coins[i];
            return 1e9;
        }
        // take
        int take = 1e9;
        if (coins[i] <= amount) {
            take = 1 + mini(i, amount - coins[i], coins);
        }
        // nottake
        int nottake = mini(i - 1, amount, coins);

        return min(take, nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        // int ans = mini(n - 1, amount, coins);
        // if (ans == 1e9)
        //     return -1;
        // return ans;

        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
        for (int j = 0; j <= amount; j++) {
            if (j % coins[0] == 0)
                dp[0][j] = j / coins[0];
            else
                dp[0][j] = 1e9;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= amount; j++) {
                int take = 1e9;
                if (coins[i] <= j) {
                    take = 1 + dp[i][j - coins[i]];
                }
                // nottake
                int nottake = dp[i - 1][j];

                dp[i][j] = min(take, nottake);
            }
        }
       int ans = dp[n-1][amount];
       if(ans == 1e9) return -1;
       else return ans;
    }
};
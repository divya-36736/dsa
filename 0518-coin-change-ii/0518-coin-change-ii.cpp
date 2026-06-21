
class Solution {
public:
    int change(int amount, vector<int>& coins) {

        int n = coins.size();

        vector<vector<unsigned long long>> dp(
            n, vector<unsigned long long>(amount + 1, 0));

        for (int j = 0; j <= amount; j++) {
            if (j % coins[0] == 0)
                dp[0][j] = 1;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= amount; j++) {

                unsigned long long take = 0;

                if (coins[i] <= j)
                    take = dp[i][j - coins[i]];

                unsigned long long nottake = dp[i - 1][j];

                dp[i][j] = take + nottake;
            }
        }

        return (int)dp[n - 1][amount];
    }
};
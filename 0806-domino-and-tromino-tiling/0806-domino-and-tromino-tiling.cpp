class Solution {
public:
    const long mod = 1e9 + 7;

    long dominoes(int i, int n, bool possible, vector<vector<long>>& dp) {
        if (i == n) return !possible;
        if (i > n) return 0;

        if (dp[i][possible] != -1) return dp[i][possible];

        long res = 0;
        if (possible) {
            // If there is a hanging cell, we must cover it
            res = (dominoes(i + 1, n, false, dp) +
                   dominoes(i + 1, n, true, dp)) % mod;
        } else {
            // Normal case: we can place vertical, horizontal, or tromino
            res = (dominoes(i + 1, n, false, dp) +
                   dominoes(i + 2, n, false, dp) +
                   2L * dominoes(i + 2, n, true, dp)) % mod;
        }

        return dp[i][possible] = res;
    }

    int numTilings(int n) {
        vector<vector<long>> dp(n + 1, vector<long>(2, -1));
        return (int)dominoes(0, n, false, dp);
    }
};

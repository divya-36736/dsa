class Solution {
public:
    int solve(int n, vector<int>& dp) {
        if (n == 0)
            return 0;
        if (dp[n] != -1)
            return dp[n];
        int ans = INT_MAX;

        for (int i = 1; i * i <= n; i++) {
            ans = min(ans, 1 + solve(n - i * i, dp));
        }
        return dp[n] = ans;
    }
    int numSquares(int n) {
        vector<int> dp(n + 1, 0);
        // return solve(n, dp);
        for (int tar = 1; tar <= n; tar++) {
            int ans = INT_MAX;
            for (int i = 1; i * i <= tar; i++) {
                ans = min(ans, 1 + dp[tar - i * i]);
            }
            dp[tar] = ans;
        }
        return dp[n];
    }
};
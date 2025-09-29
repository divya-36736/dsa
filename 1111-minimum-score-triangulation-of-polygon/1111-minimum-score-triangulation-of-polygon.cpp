class Solution {
public:
    int solve(int i, int j, vector<int>& values, vector<vector<int>>&dp) {
        // base case: no triangle possible
        if (j - i < 2)
            return 0;
        
        if(dp[i][j] != -1) return dp[i][j];

        int ans = INT_MAX;

        // try all possible k between i and j
        for (int k = i + 1; k < j; k++) {
            int cost = values[i] * values[j] * values[k] + solve(i, k, values, dp) +
                       solve(k, j, values, dp);
            ans = min(ans, cost);
        }
        dp[i][j] = ans;
        return dp[i][j];
    }
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>>dp(n, vector<int>(n, -1));
        return solve(0, n - 1, values, dp);
    }
};
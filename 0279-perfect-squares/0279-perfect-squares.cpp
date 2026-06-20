class Solution {
public:
    int solve(int i, int target, vector<int>& power, vector<vector<int>>& dp) {
        if (target == 0)
            return 0;
        if (i >= power.size())
            return 1e9;

        if (dp[i][target] != -1)
            return dp[i][target];

        int take = 1e9;
        if (power[i] <= target) {
            take = 1 + solve(i, target - power[i], power, dp);
        }

        int nottake = solve(i + 1, target, power, dp);

        return dp[i][target] = min(take, nottake);
    }
    int numSquares(int n) {
        vector<int> power;
        for (int i = 1; i * i <= n; i++) {
            power.push_back(i * i);
        }

        vector<vector<int>> dp(power.size(), vector<int>(n + 1, 0));
        // return solve(0, n, power, dp);
        int m = power.size();

        vector<int>prev(n+1, 0);
        
        //prev[0] = 0;
        

        for(int sum = 1; sum<=n; sum++){
            prev[sum] = sum;
        }


        for (int i = 1; i < m; i++) {
            vector<int>curr(n+1, 0);
            for (int sum = 1; sum <= n; sum++) {
                int take = 1e9;
                if (power[i] <= sum) {
                    take = 1 + curr[sum-power[i]];
                }

                int nottake = prev[sum];

               curr[sum] = min(take, nottake);
            }
            prev =  curr;
        }
        return prev[n];
    }
};
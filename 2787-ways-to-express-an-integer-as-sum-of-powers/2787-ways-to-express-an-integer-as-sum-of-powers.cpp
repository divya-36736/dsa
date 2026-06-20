class Solution {
public:
    int const mod = 1e9+7;
    
    int solve(int i, int n, vector<int>&power, vector<vector<int>>&dp){
        if(n == 0) return 1;
        if(i >= power.size()) return 0;

        if(dp[i][n] != -1) return dp[i][n];

        //take
        int take = 0;
        if(power[i]<=n){
            take = solve(i+1, n-power[i], power, dp);
        }
        //nottake
        int nottake = solve(i+1, n, power, dp);

        return dp[i][n] = (take+nottake)%mod;
    }
    int numberOfWays(int n, int x) {
        vector<int>power;
        for(int i = 1; ; i++){
            long long val = pow(i, x);
            if(val > n) break;
            power.push_back(val);
        }
        int m = power.size();
        vector<vector<int>>dp(m, vector<int>(n+1, 0));
        //return solve(0, n, power, dp);
        //base case
        for(int i = 0; i<m; i++){
            dp[i][0] = 1;
        }
        if(power[0] <= n){
            dp[0][power[0]] = 1;
        }
        
        for(int i = 1; i<m; i++){
            for(int j = 1; j<=n; j++){
                int take = 0;
                if(power[i]<=j){
                    take = dp[i-1][j-power[i]];
                }
                //nottake
                int nottake = dp[i-1][j];

                dp[i][j] = (take + nottake)%mod;
            }
        }
        return dp[m-1][n];
    }
};
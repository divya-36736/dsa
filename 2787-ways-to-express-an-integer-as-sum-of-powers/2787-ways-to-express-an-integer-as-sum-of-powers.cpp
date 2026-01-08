class Solution {
public:
    static const int MOD = 1e9 + 7;
    vector<int>powers;
    int solve(int i, int rem, vector<vector<int>>&dp){
        //base case
        if(rem == 0) return 1;
        if(rem < 0 || i == powers.size()) return 0;
        if(dp[i][rem] != -1) return dp[i][rem];
        //take 
        int take = solve(i+1, rem - powers[i], dp);
        int notTake = solve(i+1, rem, dp);

        return dp[i][rem] = (take+notTake)%MOD;
        
    }
    int numberOfWays(int n, int x) {
        for (int i = 1; ; i++) {
            long long val = pow(i, x);
            if (val > n) break;
            powers.push_back(val);
        }
        //like we find a vector [1, 4, 9];
        //in this we do take not take
        //show tle then we take dp
        vector<vector<int>>dp(powers.size(), vector<int>(n+1, -1));
       return solve(0, n, dp);
    }
};
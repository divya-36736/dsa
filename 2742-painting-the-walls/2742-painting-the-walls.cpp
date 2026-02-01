class Solution {
public:
    int solve(vector<int>&cost, vector<int>&time, int i, int walls, vector<vector<int>>&dp){
        if(walls <= 0) return 0;
        if(i>=cost.size()) return 1e9;
        if(dp[i][walls] != -1) return dp[i][walls];
        //take not take according to minnimum cost
        int take = cost[i] + solve(cost, time, i+1, walls-time[i]-1, dp);
        int notTake = solve(cost, time, i+1, walls, dp);
        return dp[i][walls] = min(take, notTake);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size(); //number of walls
        vector<vector<int>>dp(501, vector<int>(n+1, -1));
        return solve(cost, time, 0, n, dp);
    }
};
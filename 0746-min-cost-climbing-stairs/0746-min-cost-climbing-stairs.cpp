class Solution {
public:
    int memo(int i, vector<int>&cost, vector<int>&dp){
        if(i>=cost.size()) return 0;

        if(dp[i] != -1) return dp[i];
        dp[i] = cost[i]+min(memo(i+1, cost, dp), memo(i+2, cost, dp));
        return dp[i];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n+1, -1);
        return min(memo(0, cost, dp), memo(1, cost, dp));
    }
};
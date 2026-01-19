class Solution {
public:
    int f(int i, int j, vector<int>&cuts, vector<vector<int>>&dp){
        //base case
        if(i>j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int mini = INT_MAX;
        for(int idx = i; idx<=j; idx++){
            int ans = cuts[j+1]-cuts[i-1] + f(i, idx-1, cuts, dp) +f(idx+1, j, cuts, dp);
            mini = min(mini, ans);
        }
        return dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
    int c = cuts.size();

    // Add boundaries
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());

    // dp[i][j] = min cost to cut between cuts[i-1] and cuts[j+1]
    vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));

    for (int i = c; i >= 1; i--) {
        for (int j = i; j <= c; j++) {
            int mini = INT_MAX;
            for (int idx = i; idx <= j; idx++) {
                int cost = cuts[j + 1] - cuts[i - 1]
                           + dp[i][idx - 1]
                           + dp[idx + 1][j];
                mini = min(mini, cost);
            }
            dp[i][j] = mini;   
        }
    }

    return dp[1][c]; 
}
};
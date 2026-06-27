class Solution {
public:

    int solve(int l, int c, vector<int>& cuts, vector<vector<int>>&dp){

        if(l > c)
            return 0;

        if(dp[l][c] != -1) return dp[l][c];

        int mini = INT_MAX;

        for(int i=l;i<=c;i++){

            int cost =
                cuts[c+1]-cuts[l-1]
                + solve(l,i-1,cuts, dp)
                + solve(i+1,c,cuts, dp);

            mini=min(mini,cost);
        }

        return dp[l][c] = mini;
    }

    int minCost(int n, vector<int>& cuts) {

        int c=cuts.size();

        cuts.push_back(0);
        cuts.push_back(n);

        sort(cuts.begin(),cuts.end());
        vector<vector<int>>dp(c+1, vector<int>(c+1, -1));
        return solve(1,c,cuts, dp);
    }
};
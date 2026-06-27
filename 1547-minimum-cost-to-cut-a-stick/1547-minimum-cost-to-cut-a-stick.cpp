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

        sort(cuts.begin(), cuts.end());

    vector<vector<int>> dp(c+2, vector<int>(c+2, 0));

    // Base case:
    // dp[i][j] = 0 when i > j (already initialized)

    for(int i = c; i >= 1; i--){

        for(int j = i; j <= c; j++){

            int mini = INT_MAX;

            for(int ind = i; ind <= j; ind++){

                int cost =
                    cuts[j+1] - cuts[i-1]
                    + dp[i][ind-1]
                    + dp[ind+1][j];

                mini = min(mini, cost);
            }

            dp[i][j] = mini;
        }
    }

    return dp[1][c];
    }
};
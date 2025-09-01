class Solution {
public:
    int solve(int i, int j,string &s, string &rev, vector<vector<int>>&dp){
        int n = s.size();
        if(i == n || j == n) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == rev[j]){
            dp[i][j] = 1+solve(i+1,j+1, s, rev, dp);
        }else{
            dp[i][j] = max(solve(i+1, j, s, rev, dp), solve(i, j+1, s, rev, dp));
        }
        return dp[i][j];
    }
    int minInsertions(string s) {
        int n = s.size();
        string rev = s;
        reverse(rev.begin(), rev.end());
        vector<vector<int>>dp(n, vector<int>(n, -1));
        return n-solve(0, 0, s, rev, dp);
    }
};
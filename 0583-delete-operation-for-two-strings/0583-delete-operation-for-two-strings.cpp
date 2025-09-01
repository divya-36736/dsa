class Solution {
public:
    int solve(int i, int j,string &word1, string &word2, vector<vector<int>>&dp){
        int n = word1.size();
        int m = word2.size();
        if(i == n || j == m) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(word1[i] == word2[j]){
            dp[i][j] = 1+solve(i+1,j+1, word1, word2, dp);
        }else{
            dp[i][j] = max(solve(i+1, j, word1, word2, dp), solve(i, j+1, word1, word2, dp));
        }
        return dp[i][j];
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>>dp(n, vector<int>(m, -1));
        return n-solve(0, 0, word1, word2,dp) + m - solve(0, 0, word1, word2,dp);
    }
};
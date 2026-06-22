class Solution {
public:
    int lcs(int i, int j, string &s, string &t, vector<vector<int>>&dp){
        if(i == 0 || j == 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        //match
        if(s[i-1] == t[j-1]){
            dp[i][j] = 1+lcs(i-1, j-1, s, t, dp);
        }
        else{
            dp[i][j] = max(lcs(i-1, j, s, t, dp), lcs(i, j-1, s, t ,dp));
        }
        return dp[i][j];
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        int k=  lcs(n, m, word1, word2, dp);
        return (n-k)+(m-k);
    }
};
class Solution {
public:
    int longgesplainsub(int i, int j, string &s, string &t, vector<vector<int>>&dp){
        if(i == 0 || j == 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        //matching
        if(s[i-1] == t[j-1]){
            dp[i][j] = 1+longgesplainsub(i-1, j-1, s, t, dp);
        }
        else{//notmmatching
            dp[i][j] = max(longgesplainsub(i-1, j, s, t, dp), longgesplainsub(i, j-1, s, t, dp));
        }
        return dp[i][j];
    }
    int lcs(string &s, string &t){
        int n =s.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
        //return longgesplainsub(n, n, s, t, dp);
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=n; j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][n];
    }
    int minInsertions(string s) {
        int n =s.size();
        string t = s;
        reverse(s.begin(), s.end());
        return n-lcs(s, t);
    }
};
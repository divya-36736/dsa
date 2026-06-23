class Solution {
public:
    int solve(int i, int j, string &s, string &t, vector<vector<int>>&dp){
        if(i<0){
            //means s empty "" then add all s2/t
            return j+1;
        }
        if(j<0){
           // means t is emoty "" then delete all s1/s
           return i+1;
        }

        if(dp[i][j] != -1) return dp[i][j];
        //if match
        if(s[i] == t[j]){
            //not required any operation
            dp[i][j]  = solve(i-1, j-1, s, t, dp);
        }else{ //notmatch //replace(i-1, j-1), //delete(i-1, j) //insert(i, j-1)
            dp[i][j] = 1+min(solve(i-1, j-1, s, t, dp), min(solve(i-1, j, s, t, dp), solve(i, j-1, s, t, dp)));
        }
        return dp[i][j];
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>>dp(n, vector<int>(m, -1));
        return solve(n-1, m-1, word1, word2, dp);
    }
};
class Solution {
public:
    int lcs(int i, int j, int n1, int n2, string &text1, string &text2, vector<vector<int>> &dp) {
        if (i == n1 || j == n2) return 0;  
        if (dp[i][j] != -1) return dp[i][j];

        if (text1[i] == text2[j]) {
            dp[i][j] = 1 + lcs(i + 1, j + 1, n1, n2, text1, text2, dp);
        } else {
            dp[i][j] = max(
                lcs(i + 1, j, n1, n2, text1, text2, dp),
                lcs(i, j + 1, n1, n2, text1, text2, dp)
            );
        }
        return dp[i][j];
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>> dp(n1, vector<int>(n2, -1));
        return lcs(0, 0, n1, n2, text1, text2, dp);
    }
};

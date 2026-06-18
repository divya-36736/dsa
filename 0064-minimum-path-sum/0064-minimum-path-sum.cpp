class Solution {
public:
    int help(int i, int j, int n, int m, vector<vector<int>>&grid, vector<vector<int>>&dp){
        if(i == 0 && j == 0) return grid[i][j];
        if(i<0 || j<0) return 1e9;
        if(dp[i][j] != -1) return dp[i][j];
        
        int up = help(i-1, j, n, m, grid, dp);
        int left = help(i, j-1, n, m, grid, dp);

        return dp[i][j] = grid[i][j] + min(up, left);
    }
    int minPathSum(vector<vector<int>>& grid) {
       int n = grid.size();
       int m = grid[0].size();

       vector<vector<int>>dp(n, vector<int>(m, -1));
       return help(n-1, m-1, n, m, grid, dp); 
    }
};
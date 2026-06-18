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

       //vector<vector<int>>dp(n, vector<int>(m, 0));
       //return help(n-1, m-1, n, m, grid, dp); 
       vector<int>prev(m, 0);

       for(int i = 0; i<n; i++){
        vector<int>temp(m, 0);
        for(int j = 0; j<m; j++){
            if(i == 0 && j == 0){
                temp[j] = grid[i][j];
                continue;
            }
            int up = 1e9;
            int left = 1e9;
            if(i>0) up = prev[j];
            if(j>0) left = temp[j-1];
            temp[j] = grid[i][j] + min(up, left);
        }
        prev = temp;
       }
       return prev[m-1];
    }
};
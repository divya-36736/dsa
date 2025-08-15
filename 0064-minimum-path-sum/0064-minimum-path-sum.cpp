class Solution {
public:
    int sum(int i, int j, vector<vector<int>>& grid, vector<vector<int>>&dp){
        //base acse
        if(i == 0 && j==0){
            return grid[0][0];
        }
        //out of bound
        if(i<0 || j<0) return 1e9;
        //already visited
        if(dp[i][j] != -1) return dp[i][j];
        //if not visisted the we compute it
        int up  = sum(i-1, j, grid, dp);
        int left = sum(i, j-1, grid, dp);
        
        return dp[i][j] = grid[i][j] + min(up, left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // vector<vector<int>>dp(n, vector<int>(m, -1));
        // return sum(n-1, m-1, grid, dp);

        //tabulation
        //1st dp 2d vector
        
        vector<vector<int>>dp(n, vector<int>(m, 0));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                //base case 
                if(i == 0 && j==0){
                   dp[i][j] =  grid[i][j];
                   continue;
                }
                //now check in up and left
                int up = grid[i][j];
                if(i>0) up += dp[i-1][j];
                else up += 1e9;
                //now in left
                int left = grid[i][j];
                if(j>0) left += dp[i][j-1];
                else left += 1e9; 

                dp[i][j] = min(up, left);
            }
        }
        return dp[n-1][m-1];
    }
};
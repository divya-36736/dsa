class Solution {
public:
    int count(int i, int j, int n, int m, vector<vector<int>>& obstacleGrid, vector<vector<int>>&dp){
        // if(i<0 || j<0) return 0;

        // //for obstacle
        // if(obstacleGrid[i][j] == 1) return 0;

        // if(i == 0 && j==0){
        //     return 1;
        // }

        // int up = count(i-1, j, n, m, obstacleGrid);
        // int left = count(i, j-1, n, m, obstacleGrid);
        // return up+left;

        //memo

        //out of boundary return 0
        if(i<0 || j<0) return 0;
        //if obstacle aae toh return 0
        if(obstacleGrid[i][j] == 1) return 0;
        //base case
        if(i == 0 && j == 0) return 1;
        
        //if visited 
        if(dp[i][j] != -1) return dp[i][j];

        int up = count(i-1, j, n, m, obstacleGrid, dp);
        int left = count(i, j-1, n, m, obstacleGrid, dp);

        return dp[i][j] = up+left;

    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        //now using dp
        vector<vector<int>>dp(n, vector<int>(m,-1));
        return count(n-1, m-1, n, m, obstacleGrid, dp);
    }
};
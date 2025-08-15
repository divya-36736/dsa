class Solution {
public:
    // int count(int i, int j, int n, int m, vector<vector<int>>& obstacleGrid, vector<vector<int>>&dp){
        // if(i<0 || j<0) return 0;

        // //for obstacle
        // if(obstacleGrid[i][j] == 1) return 0;

        // if(i == 0 && j==0){
        //     return 1;
        // }

        // int up = count(i-1, j, n, m, obstacleGrid);
        // int left = count(i, j-1, n, m, obstacleGrid);
        // return up+left;



        //memoization
        //out of boundary return 0
    //     if(i<0 || j<0) return 0;
    //     //if obstacle aae toh return 0
    //     if(obstacleGrid[i][j] == 1) return 0;
    //     //base case
    //     if(i == 0 && j == 0) return 1;
        
    //     //if visited 
    //     if(dp[i][j] != -1) return dp[i][j];

    //     int up = count(i-1, j, n, m, obstacleGrid, dp);
    //     int left = count(i, j-1, n, m, obstacleGrid, dp);

    //     return dp[i][j] = up+left;

    // }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        //now using dp
        // vector<vector<int>>dp(n, vector<int>(m,-1));
        // return count(n-1, m-1, n, m, obstacleGrid, dp);

        //tabulation
        //base case
        // vector<vector<int>>dp(n, vector<int>(m,0));
        // for(int i = 0; i<n; i++){
        //     for(int j = 0; j<m; j++){
        //         if (obstacleGrid[i][j] == 1) {
        //         dp[i][j] = 0; // obstacleGrid cell
        //         continue;
        //     }
        //         if(i == 0 && j==0){
        //             dp[i][j] = 1;
        //             continue;
        //         }
        //         int up = 0;
        //         int left =0;
        //         if(i>0) up = dp[i-1][j];
        //         if(j>0) left = dp[i][j-1];
        //         dp[i][j] = left+up;
        //     }
        // }
        // return dp[n-1][m-1];

        //space optimized
        vector<int>prev(m, 0); //represent prev row
        for(int i = 0; i<n; i++){
            vector<int>temp(m,0); //store current row 
            for(int j = 0; j<m; j++){
                if (obstacleGrid[i][j] == 1) {
                temp[j] = 0; // obstacleGrid cell
                continue;
            }
                if(i == 0 && j==0){
                    temp[j] = 1;
                    continue;
                }
                int up = 0;
                int left =0;
                if(i>0) up = prev[j];
                if(j>0) left = temp[j-1];
                temp[j] = left+up;
            }
            prev = temp;
        }
        return prev[m-1];
    }
};
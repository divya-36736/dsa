class Solution {
public:

    int help(int i, int j, vector<vector<int>>& obstacleGrid, vector<vector<int>>&dp){
        if(i < 0 || j < 0) return 0;
        if(obstacleGrid[i][j] == 1) return 0;
        if(i == 0 && j == 0) return 1;

        if(dp[i][j] != -1) return dp[i][j];

        int up = help(i - 1, j, obstacleGrid, dp);
        int left = help(i, j - 1, obstacleGrid, dp);

        return dp[i][j]=up + left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        //vector<vector<int>>dp(n, vector<int>(m, 0));
        //return help(n - 1, m - 1, obstacleGrid, dp);
        vector<int>prev(m, 0);

        for(int i = 0; i<n; i++){
            vector<int>temp(m, 0);
            for(int j = 0; j<m; j++){
                if(obstacleGrid[i][j] == 1){
                    temp[j] = 0;
                    continue;
                }
                if(i == 0 && j == 0) {
                    temp[j] = 1;
                    continue;
                }
                int up = 0, left = 0;
                if(i>0) up = prev[j];
                if(j>0) left = temp[j-1];
                temp[j] = up+left;
            }
            prev = temp;
        }
        return prev[m-1];
    }
};
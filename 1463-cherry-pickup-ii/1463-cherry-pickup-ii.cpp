class Solution {
public:
    int f(int i, int j1, int j2, vector<vector<int>>& grid,
          vector<vector<vector<int>>>& dp) {
        int m = grid[i].size();
        int n = grid.size();

        if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m) {
            return -1e9;
        }

        if (i == n - 1) {
            if (j1 == j2)
                return grid[i][j1];
            else
                return grid[i][j1] + grid[i][j2];
        }

        if (dp[i][j1][j2] != -1)
            return dp[i][j1][j2];

        int maxi = 0;
        for (int di1 = -1; di1 <= +1; di1++) {
            for (int dj2 = -1; dj2 <= +1; dj2++) {
                if (j1 == j2)
                    maxi = max(maxi, grid[i][j1] + f(i + 1, j1 + di1, j2 + dj2,
                                                     grid, dp));
                else
                    maxi =
                        max(maxi, grid[i][j1] + grid[i][j2] +
                                      f(i + 1, j1 + di1, j2 + dj2, grid, dp));
            }
        }
        return dp[i][j1][j2] = maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(m, 0)));
        // return f(0, 0, m-1, grid, dp);
        // base case
        //  if(i == n-1){
        //      if(j1 == j2) return grid[i][j1];
        //      else return grid[i][j1]+grid[i][j2];
        //  } this base case in terms of tabulation

        for (int j1 = 0; j1 < m; j1++) {
            for (int j2 = 0; j2 < m; j2++) {
                if (j1 == j2)
                    dp[n - 1][j1][j2] = grid[n - 1][j1];
                else
                    dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
            }
        }

        for (int i = n - 2; i >= 0; i--) {
            for (int j1 = 0; j1 < m; j1++) {
                for (int j2 = 0; j2 < m; j2++) {
                    int maxi = -1e9;
                    int curr = (j1 == j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2];
                    // Try all 9 moves
                    for (int dj1 = -1; dj1 <= 1; dj1++) {
                        for (int dj2 = -1; dj2 <= 1; dj2++) {
                            int newJ1 = j1 + dj1;
                            int newJ2 = j2 + dj2;
                            if (newJ1 >= 0 && newJ1 < m && newJ2 >= 0 && newJ2 < m) {
                                maxi = max(maxi, curr + dp[i + 1][newJ1][newJ2]);
                            } else {
                                maxi = max(maxi, (int)-1e9);
                            }
                        }
                    }
                    dp[i][j1][j2] = maxi;
                }
            }
        }
        return dp[0][0][m - 1];
    }
};
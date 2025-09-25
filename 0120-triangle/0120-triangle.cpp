// class Solution {
// public:
//     int n;

//     int dfs(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
//         // base case: last row
//         if (i == n - 1) return triangle[i][j];

//         // return if already computed
//         if (dp[i][j] != -1) return dp[i][j];

//         // move down or diagonal right
//         int down = triangle[i][j] + dfs(i + 1, j, triangle, dp);
//         int diag = triangle[i][j] + dfs(i + 1, j + 1, triangle, dp);

//         return dp[i][j] = min(down, diag);
//     }

//     int minimumTotal(vector<vector<int>>& triangle) {
//         n = triangle.size();
//         // initialize memoization table
//         vector<vector<int>> dp(n, vector<int>(n, -1));
//         return dfs(0, 0, triangle, dp);
//     }
// };

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp = triangle[n-1]; // start with last row

        // bottom-up
        for(int i = n-2; i >= 0; i--){
            for(int j = 0; j <= i; j++){
                dp[j] = triangle[i][j] + min(dp[j], dp[j+1]);
            }
        }

        return dp[0];
    }
};

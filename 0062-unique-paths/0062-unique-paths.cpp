// class Solution {
// public:
//     int count(int i, int j, int m, int n){
//         if(i == 0 && j == 0){
//             return 1;
//         }
//         if(i<0 || j<0){
//             return 0;
//         }
//         int up = count(i-1, j, m, n);
//         int left = count(i, j-1, m, n);
//         return left+up;
//     }
//     int uniquePaths(int m, int n) {
//         return count(m-1, n-1, m, n);
//     }
// };

// //due to constrainst we use dp
// class Solution {
// public:
//     int count(int i, int j, int m, int n, vector<vector<int>>&dp){
//         if(i == 0 && j == 0){
//             return 1;
//         }
//         if(i<0 || j<0){
//             return 0;
//         }
//         if(dp[i][j] != -1) return dp[i][j];

//         int up = count(i-1, j, m, n,dp);
//         int left = count(i, j-1, m, n, dp);
//         return dp[i][j] = left+up;
//     }
//     int uniquePaths(int m, int n) {
//         vector<vector<int>>dp(m,vector(n, -1));
//         return count(m-1, n-1, m, n,dp);
//     }
// };

// tabulation bottom to up(base case to main case)
class Solution {
public:
    int uniquePaths(int m, int n) {
        // //in tabulation is easy to memoization
        // 1. make a dp vector same size
        // 1. declare base case
        // 3. express all stuffs in the for loop
        // 4. copy the recursive
        // vector<vector<int>> dp(m, vector<int>(n, 0));
        // dp[0][0] = 1;

        // for (int i = 0; i < m; i++) {
        //     for (int j = 0; j < n; j++) {
        //         if (i == 0 && j == 0) continue;
        //         int up = 0, left = 0;
        //         if (i > 0) up = dp[i - 1][j];
        //         if (j > 0) left = dp[i][j - 1];
        //         dp[i][j] = up + left;
        //     }
        // }
        // return dp[m - 1][n - 1];

        //space optimized
        vector<int>prev(n, 0); //it represent the prev row
        prev[0] = 1;

        for (int i = 0; i < m; i++) {
            vector<int>temp(n, 0); // temp will store the current row's results
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0){
                    temp[j] = 1;
                    continue;
                } 
                
                int up = 0, left = 0;
                if (i > 0) up = prev[j]; //what is dp[i-1] prev and what is dp[i] is curr
                if (j > 0) left = temp[j - 1];
                temp[j] = up + left;
               
            }
            prev = temp; //this do after one row complete
        }
        return prev[n - 1];//it’s the last column of the 
        //last processed row.
    }
};

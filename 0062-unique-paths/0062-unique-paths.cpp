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

//due to constrainst we use dp
class Solution {
public:
    int count(int i, int j, int m, int n, vector<vector<int>>&dp){
        if(i == 0 && j == 0){
            return 1;
        }
        if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];

        int up = count(i-1, j, m, n,dp);
        int left = count(i, j-1, m, n, dp);
        return dp[i][j] = left+up;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector(n, -1));
        return count(m-1, n-1, m, n,dp); 
    }
};
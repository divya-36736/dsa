class Solution {
public:
    int minsum(int i, int j, int n, vector<vector<int>>&triangle, vector<vector<int>>&dp){
        if(i>=n || j<0 || j>i) return 1e9;
        if(dp[i][j] != -1) return dp[i][j];

        if(i == n-1) return triangle[i][j];

        int down = minsum(i+1, j, n, triangle, dp);
        int right = minsum(i+1, j+1, n, triangle, dp);

        return dp[i][j] = triangle[i][j] + min(down, right);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        //vector<vector<int>>dp(n, vector<int>(n, 0));
        //return minsum(0, 0, n, triangle, dp);
        vector<int>front(n, 0);

        for(int i = 0; i<triangle[n-1].size(); i++){
            front[i] = triangle[n-1][i];
        }

        vector<int>curr(n, 0);
        for(int i = n-2; i>=0; i--){
            for(int j = 0; j<triangle[i].size(); j++){
                int down = front[j];
                int right = front[j+1];

                curr[j] = triangle[i][j] + min(down, right);
            }
            front = curr;
        }
        return front[0];
    }
};
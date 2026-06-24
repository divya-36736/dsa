class Solution {
public:
    int solve(int i, int prev, vector<int>& nums, vector<vector<int>>& dp) {
        int n = nums.size();
        if (i == n)
            return 0;
        if (dp[i][prev + 1] != -1)
            return dp[i][prev + 1];
        // take nottake
        int take = 0;
        if (prev == -1 || nums[prev] < nums[i]) {
            take = 1 + solve(i + 1, i, nums, dp);
        }
        int nottake = solve(i + 1, prev, nums, dp);
        return dp[i][prev + 1] = max(take, nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        //vector<vector<int>> dp(n+1, vector<int>(n + 1, 0));
        // return solve(0, -1, nums, dp);
        vector<int>prev(n+1, 0), curr(n+1, 0);

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i-1; j >= -1; j--) {
                int take = 0;
                if (j == -1 || nums[j] < nums[i]) {
                    take = 1 + prev[i+1];
                }
                int nottake = prev[j+1];
                curr[j + 1] = max(take, nottake);
            }
            prev = curr;
        }
        return prev[0];
    }
};
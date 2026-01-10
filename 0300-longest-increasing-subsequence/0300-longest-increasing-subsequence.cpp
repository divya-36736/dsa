class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for (int i = n-1; i >= 0; i--) {
            for (int prev_i = i-1; prev_i >= -1; prev_i--) {

                int len = dp[i+1][prev_i + 1]; // not take

                if (prev_i == -1 || nums[prev_i] < nums[i]) {
                    len = max(len, 1 + dp[i+1][i+1]); // take
                }

                dp[i][prev_i + 1] = len;
            }
        }
        return dp[0][0];
    }
};

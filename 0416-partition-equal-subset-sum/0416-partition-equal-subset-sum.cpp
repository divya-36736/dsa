class Solution {
public:
    bool solve(int i, int tar, vector<int>& nums, vector<vector<bool>>& dp) {
        if (tar == 0)
            return true;
        if (i >= nums.size())
            return false;

        if (dp[i][tar] != false)
            return dp[i][tar];

        bool take = false;
        if (nums[i] <= tar) {
            take = solve(i + 1, tar - nums[i], nums, dp);
        }
        bool nottake = solve(i + 1, tar, nums, dp);

        return dp[i][tar] = take || nottake;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totsum = 0;
        for (auto& it : nums) {
            totsum += it;
        }

        if (totsum % 2 != 0)
            return 0;
        else {
            int k = (totsum) / 2;
            vector<vector<bool>> dp(n, vector<bool>(k + 1, false));
            // return solve(0, k, nums, dp);
            for (int i = 0; i < n; i++) {
                dp[i][0] = true;
            }

            if (nums[0] <= k) {
                dp[0][nums[0]] = true;
            }

            for (int i = 1; i < n; i++) {
                for (int sum = 1; sum <= k; sum++) {
                    bool take = false;
                    if (nums[i] <= sum) {
                        take = dp[i-1][sum-nums[i]];
                    }
                    bool nottake = dp[i-1][sum];

                    dp[i][sum] = take || nottake;
                }
            }
            return dp[n-1][k];
        }
        
    }
};
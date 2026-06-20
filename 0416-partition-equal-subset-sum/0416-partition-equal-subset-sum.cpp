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
           // vector<vector<bool>> dp(n, vector<bool>(k + 1, false));
            // return solve(0, k, nums, dp);

            vector<bool>prev(k+1, false);

            prev[0] = true;
            

            if (nums[0] <= k) {
                prev[nums[0]] = true;
            }

            for (int i = 1; i < n; i++) {
                vector<bool>curr(k+1, false);
                for (int sum = 1; sum <= k; sum++) {
                    bool take = false;
                    if (nums[i] <= sum) {
                        take = prev[sum-nums[i]];
                    }
                    bool nottake = prev[sum];

                    curr[sum] = take || nottake;
                }
                prev = curr;
            }
            return prev[k];
        }
        
    }
};
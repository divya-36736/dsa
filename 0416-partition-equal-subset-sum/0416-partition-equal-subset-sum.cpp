class Solution {
public:
    bool solve(int i, int k, vector<vector<int>>& dp, vector<int>& nums) {
        // base case
        if (k == 0)
            return true; // k sum hai aur target hai
        if (i == 0) {    // i==0 at 0 index
            return nums[0] == k;
        }

        // check in dp , is visisted or not
        if (dp[i][k] != -1)
            return dp[i][k];

        // not take
        bool nottake = solve(i - 1, k, dp, nums);

        // take
        bool take = false;
        if (nums[i] <= k) {
            take = solve(i - 1, k - nums[i], dp, nums);
        }
        return dp[i][k] = take || nottake;
    }
    bool canPartition(vector<int>& nums) {
        // size of the array
        int n = nums.size();
        // int totsum = 0;
        // for (int i = 0; i < n; i++) { // totalsum
        //     totsum += nums[i];
        // }
        // if (totsum % 2 != 0)
        //     return false; // not even
        // else {            // if even
        //     int k = (totsum / 2);
        //     // vector<vector<int>>dp(n, vector<int>(k+1, -1));

        //     // return solve(n-1, k, dp, nums);

        //     // tabulation
        //     vector<vector<bool>> dp(n, vector<bool>(k + 1,false));
        //     // base case
        //     for (int i = 0; i < n; i++) {
        //         dp[i][0] = true;
        //     }
        //     if (nums[0] <= k)
        //         dp[0][nums[0]] = true;
        //     // loop
        //     for (int i = 1; i < n; i++) {
        //         for (int target = 0; target<=k; target++) {
        //             // not take
        //             bool nottake = dp[i-1][target];

        //             // take
        //             bool take = false;
        //             if (nums[i] <= target) {
        //                 take = dp[i-1][target-nums[i]];
        //             }
        //             dp[i][target] = take || nottake;
        //         }
        //     }
        //     return dp[n-1][k];
        // }

        // space optimization
        int totsum = 0;
        for (int i = 0; i < n; i++) { // totalsum
            totsum += nums[i];
        }
        if (totsum % 2 != 0)
            return false; // not even
        else {            // if even
            int k = (totsum / 2);
            // vector<vector<int>>dp(n, vector<int>(k+1, -1));

            // return solve(n-1, k, dp, nums);

            // tabulation
            vector<bool>prev(k+1, false); //prev row value store
            // base case
            prev[0] = true;
            if (nums[0] <= k)
                prev[nums[0]] = true;
            // loop
            for (int i = 1; i < n; i++) {
                vector<bool>curr(k+1, false); //curr row value store
                for (int target = 0; target <= k; target++) {
                    // not take
                    bool nottake = prev[target];

                    // take
                    bool take = false;
                    if (nums[i] <= target) {
                        take = prev[target - nums[i]];
                    }
                    curr[target] = take || nottake;
                }
                prev = curr; // ✅ update
            }
            return prev[k];
        }
    }
};
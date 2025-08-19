class Solution {
public:
    int ways(int i, int target, vector<int>& nums, vector<vector<int>>& dp) {
        if(i == 0) {
            if(target == 0 && nums[0] == 0) return 2; // pick or not pick
            if(target == 0 || nums[0] == target) return 1;
            return 0;
        }

        if(dp[i][target] != -1) return dp[i][target];

        int nottake = ways(i-1, target, nums, dp);
        int take = 0;
        if(nums[i] <= target) {
            take = ways(i-1, target - nums[i], nums, dp);
        }

        return dp[i][target] = take + nottake;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totsum = 0;
        for(auto num: nums) totsum += num;

        if(totsum < abs(target) || (totsum + target) % 2 != 0) return 0;

        int s1 = (totsum + target) / 2;  // subset sum target

        vector<vector<int>> dp(n, vector<int>(s1+1, -1));
        return ways(n-1, s1, nums, dp);
    }
};

class Solution {
public:
    int ways(int i, int target, vector<int>&nums, vector<vector<int>>&dp){
        if(i == 0){
            if(target == 0 && nums[0] == 0) return 2;
            if(target == 0 || nums[0] == target) return 1;
            return 0;
        }

        if(dp[i][target] != -1) return dp[i][target];

        //take
        int take = 0;
        if(nums[i] <= target){
            take = ways(i-1, target-nums[i], nums, dp);
        }
        //not take
        int nottake = ways(i-1, target, nums, dp);

        return dp[i][target] = take+nottake;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totsum = 0;
        for(auto &it:nums){
            totsum += it;
        }
        if(totsum < abs(target) || (totsum + target)%2 != 0) return 0;
        //s1 -s2 = taregt
        //s1 + S2 = totsum
        int s1 = (totsum + target)/2;

        //vector<vector<int>>dp(n, vector<int>(s1+1, 0));
        //return ways(n-1, s1, nums, dp);
        vector<int>prev(s1+1, 0);
        if(nums[0] == 0){
            prev[0] = 2;
        }
        else{
            prev[0] = 1;
            if(nums[0]<=s1){
                prev[nums[0]] = 1;
            }
        }

        for(int i = 1; i<n; i++){
            vector<int>curr(s1+1, 0);
            for(int sum = 0; sum <=s1; sum++){
                int take = 0;
                if(nums[i] <= sum){
                take = prev[sum-nums[i]];
                }
                //not take
                int nottake = prev[sum];

                curr[sum] = take+nottake;
            }
            prev = curr;
        }
        return prev[s1];
    }
};
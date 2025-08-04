class Solution {
public:
    bool solve(int i, int k, vector<vector<int>>&dp, vector<int>&nums){
        //base case
        if(k == 0) return true;
        if(i == 0){
            return nums[0] == k;
        }


        //check in dp , is visisted or not
        if(dp[i][k] != -1) return dp[i][k];

        //not take
        bool nottake = solve(i-1, k, dp, nums);

        //take
        bool take = false;
        if(nums[i]<=k){
            take = solve(i-1, k-nums[i], dp, nums);
        }
        return dp[i][k] = take || nottake;
    }
    bool canPartition(vector<int>& nums) {
        //size of the array
        int n = nums.size();
        int totsum = 0;
        for(int i = 0; i<n; i++){
            totsum += nums[i];
        }
        if(totsum % 2 != 0) return false;
        else{
            int k = (totsum/2);
            vector<vector<int>>dp(n, vector<int>(k+1, -1));
        
            return solve(n-1, k, dp, nums);
        }
        
    }
};
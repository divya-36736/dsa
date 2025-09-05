class Solution {
public:
    int solve(int i, int prev, bool isUp, vector<int>&nums, vector<vector<vector<int>>>&dp){
        if( i == nums.size()) return 0;

        //we use isUp means next difference should be negative 
        //if now is positive
        if(dp[i][prev+1][isUp] != -1)return dp[i][prev+1][isUp];
        //nottake
        int notTake = solve(i+1,prev, isUp, nums, dp);
        //take
        int take = 0;
        if(prev == -1){
            take = 1+solve(i+1, i, isUp, nums, dp);
        }else{
            if(isUp && nums[i]>nums[prev]){ 
                take = 1+solve(i+1, i, false, nums, dp);
            }else if (!isUp && nums[i] < nums[prev]) {
                take = 1 + solve(i + 1, i, true, nums, dp);
            }
        }
        return dp[i][prev+1][isUp]= max(take, notTake);
    }
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(n+1,vector<int>(2, -1)));
        return max(solve(0, -1, true, nums, dp), solve(0, -1, false, nums, dp));
    }
};
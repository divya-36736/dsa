class Solution {
public:
    int f(int i, int m, vector<int>&nums, vector<int>&dp){
        if(i > m) return 0;

        if(dp[i] != -1) return dp[i];

        int take = nums[i]+f(i+2, m, nums, dp);
        int notTake = f(i+1, m, nums, dp);

        return dp[i] = max(take, notTake);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1) return nums[0];

        vector<int>dp1(n, -1), dp2(n, -1);

        int case1 = f(0, n-2, nums, dp1);
        int case2 = f(1, n-1, nums, dp2);
        return max(case1, case2);
    }
};
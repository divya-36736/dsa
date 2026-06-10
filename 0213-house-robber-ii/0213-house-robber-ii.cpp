class Solution {
public:
    int f(int j, int m, vector<int>&nums, vector<int>&dp){
        int n = nums.size();

        int prev2 = dp[n+1];
        int prev1 = dp[n];

        for(int i = m; i>=j; i--){
            int take = nums[i]+prev2;
            int notTake = prev1;
            prev2 = prev1;
            prev1 = max(take, notTake);
        }
        return prev1;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];

        vector<int>dp1(n+2, 0), dp2(n+2, 0);

        
        int case1 = f(0, n-2, nums, dp1);
        int case2 = f(1, n-1, nums, dp2);
        
        return max(case1, case2);
    }
};
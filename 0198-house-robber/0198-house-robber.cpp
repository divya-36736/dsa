class Solution {
public:
    // in memoization made dp vector(n+1, -1);
    //  int house(int i, vector<int>& nums, vector<int>&dp) {
    //      int n = nums.size();
    //      // base case
    //      if (i < 0)
    //          return 0; // no houses left
    //      if (i == 0)
    //          return nums[0]; // only first house
    //      if(dp[i] != -1) return dp[i];
    //      // pick
    //      int pick = nums[i] + house(i - 2, nums, dp);
    //      // not pick
    //      int not_pick = 0 + house(i - 1, nums, dp);
    //      return  dp[n-1] = max(pick, not_pick);
    //  }

    int rob(vector<int>& nums) {

        int n = nums.size();
        // recursive
        // return house(n-1, nums);
        // memoization
        // vector<int>dp(n+1, -1);
        // return house(n-1, nums, dp);

        // tabulation

        // Base case: If there are no elements in the array, return 0
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]); // base case for second house
        // iterate on from element 1 to n
            for (int i = 2; i < n; i++) {
                int pick = nums[i] + dp[i - 2]; // rob this house
                int nonPick = dp[i - 1];        // skip this house
                dp[i] = max(pick, nonPick);
            }
            return dp[n - 1];

            // n == 1 return nums[0];
            // n ==2 return max(nums[0],nums[1])

            // if(n==1) return nums[0];
            // if(n==2) return max(nums[0],nums[1]);

            // int prev2 = nums[0];
            // int prev1 = max(nums[0],nums[1]);

            // for(int i = 2 ;i<n;i++){
            //     int take = prev2 + nums[i];
            //     int notake = prev1 +0;

            //     prev2 = prev1 ;
            //     prev1 = max(take,notake);
            // }
            // return prev1;
        }
    };
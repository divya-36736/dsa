class Solution {
public:
    //this is circular house then we 1 and last house are adjcanet then we check maximum from 0 to n-2 and and 1 to n-1;
    int house(int i, int end, vector<int>&nums, vector<int>&dp){
        //memoization
        
        if (i > end) return 0; // out of range
        if (i == end) return nums[i]; // last house in range
        if(dp[i] != -1) return dp[i];
        //pick
        int pick = nums[i] + house(i+2, end, nums, dp);
        //non pick
        int nonPick = 0 + house(i+1, end, nums, dp);

        return dp[i] = max(pick, nonPick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        vector<int> dp1(n+1, -1), dp2(n+1, -1); // separate DP arrays
        //in case1 include 0 to n-2
        //in case 2 include 1 to n-1
        int case1 = house(0, n-2, nums, dp1);//1st include
        int case2 = house(1, n-1, nums, dp2);//last inlcude
        return max(case1, case2);

        // //In 1st we include zero
        // if(n==1) return nums[0];
        // if(n==2) return max(nums[0],nums[1]);

        // int prev2 = nums[0];
        // int prev1 = max(nums[0],nums[1]);

        // for(int i = 2 ;i<n-1 ;i++){
        //     int take = prev2 + nums[i];
        //     int notake = prev1+0;

        //     prev2 = prev1;
        //     prev1 =max(take,notake);

        // }

        // //in this we include nums[n-1] 
        // int prev4 = nums[n-1];
        // int prev3 = max(nums[n-1],nums[n-2]);

        // for(int i = n-3 ;i>=1 ;i--){
        //     int take = prev4 + nums[i];
        //     int notake = prev3+0;

        //     prev4 = prev3;
        //     prev3 =max(take,notake);

        // }

        // return max(prev1,prev3);
    }
};
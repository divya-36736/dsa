class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        // iterating from 0 to n-2 
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);

        int prev2 = nums[0];
        int prev1 = max(nums[0],nums[1]);

        for(int i = 2 ;i<n-1 ;i++){
            int take = prev2 + nums[i];
            int notake = prev1+0;

            prev2 = prev1;
            prev1 =max(take,notake);

        }

        int prev4 = nums[n-1];
        int prev3 = max(nums[n-1],nums[n-2]);

        for(int i = n-3 ;i>=1 ;i--){
            int take = prev4 + nums[i];
            int notake = prev3+0;

            prev4 = prev3;
            prev3 =max(take,notake);

        }

        return max(prev1,prev3);
    }
};
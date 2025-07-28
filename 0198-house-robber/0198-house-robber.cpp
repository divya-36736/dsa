class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        
        // n == 1 return nums[0];
        // n ==2 return max(nums[0],nums[1])

        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);

        int prev2 = nums[0];
        int prev1 = max(nums[0],nums[1]);

        for(int i = 2 ;i<n;i++){
            int take = prev2 + nums[i];
            int notake = prev1 +0;

            prev2 = prev1 ;
            prev1 = max(take,notake);
        }
        return prev1;
    }
};
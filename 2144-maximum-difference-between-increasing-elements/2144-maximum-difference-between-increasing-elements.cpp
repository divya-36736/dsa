class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        // int maxi = INT_MIN;
        // for(int i = 0; i<n; i++){
        //     for(int j = i+1; j<n; j++){
        //         if(nums[j]>nums[i]){
        //             maxi = max(maxi, nums[j]-nums[i]);
        //         }
        //     }
        // }
        // return maxi == INT_MIN ? -1 : maxi;
        
        int mini = nums[0];
        int maxi = -1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > mini)
                maxi = max(maxi, nums[i] - mini);
            else
                mini = nums[i];
        }
        return maxi;
    }
};
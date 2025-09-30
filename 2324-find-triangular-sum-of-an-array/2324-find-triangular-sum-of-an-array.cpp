class Solution {
public:
    // int recursion(vector<int>&nums){
    //     int n = nums.size();
    //     //base case
    //     if(n == 1) return nums[0];
    //     vector<int>ans;
    //     for(int i = 0; i<n-1; i++){
    //         int sum = 0;
    //         sum = (nums[i] + nums[i + 1]) % 10;
    //         ans.push_back(sum);
    //     }
    //     return recursion(ans);
    // }
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        for (int len = n; len > 1; len--) {
            for (int i = 0; i < len - 1; i++) {
                nums[i] = (nums[i] + nums[i + 1]) % 10;
            }
        }
        return nums[0]; // Final result
    }
};
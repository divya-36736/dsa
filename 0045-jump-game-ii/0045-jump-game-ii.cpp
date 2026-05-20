class Solution {
public:
    int minjump(vector<int>&nums, int pos, vector<int>&dp){
        int n = nums.size();
        if(pos >= n-1) return 0;

        if(nums[pos] == 0) return INT_MAX;

        int minstep = INT_MAX;

        if(dp[pos] != -1) return dp[pos];

        for(int jump=1; jump<=nums[pos]; jump++){
            
            int subres = minjump(nums, pos+jump, dp);

            if(subres != INT_MAX){
                minstep = min(minstep, 1+subres);
            }
        }
        return dp[pos] = minstep;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, -1);
        return minjump(nums, 0, dp);
    }
};
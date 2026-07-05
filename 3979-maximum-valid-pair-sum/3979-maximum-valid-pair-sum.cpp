class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>sf(n+1);
        for(int i = n-1; i>=0; i--){
            sf[i] = max(nums[i], sf[i+1]);
        }
        int ans = 0;
        for(int i = 0; i+k<n; i++){
            ans = max(ans, nums[i]+sf[i+k]);
        }
        return ans;
    }
};
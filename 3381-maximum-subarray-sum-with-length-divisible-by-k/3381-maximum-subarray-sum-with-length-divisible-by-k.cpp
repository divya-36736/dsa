class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long>minprefix(k, LLONG_MAX);
        minprefix[0] = 0;
        long long prefix = 0;
        long long ans = LLONG_MIN;
        for(int i = 0; i<n; i++){
            prefix += nums[i];
            int r = (i+1)%k;
            if(minprefix[r] != LLONG_MAX){
                ans = max(ans, prefix-minprefix[r]);
            }
            minprefix[r] = min(minprefix[r], prefix);
        }
        return ans;
    }
};
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int st = 0;
        int end = n-1;
        int ans = INT_MIN;
        while(st<end){
            int sum = nums[st]+nums[end];
            ans = max(ans, sum);
            st++;
            end--;
        }
        return ans;
    }
};
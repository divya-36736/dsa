class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        for(int i = 0; i<n; i++){
           int maxpr = 1;
            for(int j = i; j<n; j++){
                maxpr *= nums[j];
                ans = max(ans, maxpr);
            }
        }
        return ans;
    }
};
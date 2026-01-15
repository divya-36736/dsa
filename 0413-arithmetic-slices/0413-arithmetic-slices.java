class Solution {
    public int numberOfArithmeticSlices(int[] nums) {
        int n = nums.length;
        int cnt = 0;
        int ans = 0;
        for(int i = 2; i<n; i++){
            if(nums[i]- nums[i-1] == nums[i-1] - nums[i-2]){
                cnt++;
                ans += cnt;
            }else{
                cnt = 0;
            }
        }
        return ans;
    }
}
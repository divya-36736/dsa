class Solution {
public:
    int atmost(vector<int>&nums, int k){
        int n = nums.size();
        
        int l = 0;
        int r = 0;
        int cnt = 0;
        long long sum  = 0;

        while(r<n){
            sum += (nums[r]%2);
            while(sum > k){
                sum -= (nums[l]%2);
                l++;
            }
            cnt += (r-l+1);
            r++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums, k) - atmost(nums, k-1);
    }
};
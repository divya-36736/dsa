class Solution {
public:
    int atmost(vector<int>&nums, int k){
        int n = nums.size();
        int l = 0;
        int r = 0;
        int sum = 0;
        int cnt = 0;
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
        //this question is also consider the same as binarysubarray 
        //bcz we need the odd numbers theb we can put the odd with 1 and
        //even with the 0 and we require the k numbers of odd numbers then we 
        //can say same as gaol is k
        int n = nums.size();
        return atmost(nums, k)-atmost(nums, k-1);
    }
};
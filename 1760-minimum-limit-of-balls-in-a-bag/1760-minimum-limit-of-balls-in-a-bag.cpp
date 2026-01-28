class Solution {
public:
    long long calopreq(int mid, vector<int>&nums){
        long long tot = 0;
        for(int num:nums){
            tot += (num-1)/mid;
        }
        return tot;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int n = nums.size();
        int maxval = *max_element(nums.begin(), nums.end());
        int st = 1;
        int end = maxval;
        int ans = maxval;
        while(st<=end){
            int mid = st+(end - st)/2;
            long long op = calopreq(mid, nums);
            if(op<=maxOperations){
                ans = mid;
                end = mid - 1;
            }else{
                st = mid+1;
            }
        }
        return ans;
    }
};
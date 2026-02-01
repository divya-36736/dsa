class Solution {
public:
    int countPartition(vector<int>&nums, int allowValue){
        int partition = 1;
        long long subArraySum = 0;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            if(subArraySum + nums[i] <= allowValue){
                subArraySum += nums[i];

            }else{
                partition++;
                subArraySum = nums[i];
            }
        }
        return partition;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low = *max_element(nums.begin(), nums.end());
        int maxVal = 0;
        for(int num:nums){
            maxVal += num;
        }
        int ans = -1;
        int high = maxVal;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(countPartition(nums, mid) <= k){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};
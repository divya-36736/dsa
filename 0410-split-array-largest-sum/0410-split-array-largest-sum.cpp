class Solution {
public:
    int countPartition(vector<int>&nums, int maxSum){
        int n = nums.size();
        int partition = 1;
        long long subarr = 0;
        for(int i = 0; i<n; i++){
            if(subarr + nums[i] <= maxSum){
                subarr += nums[i];
            }
            else{
                partition++;
                subarr = nums[i];
            }
        }
        return partition;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(),0);
        // for(int maxSum = low; maxSum<=high; maxSum++){
        //     if(countPartition(nums, maxSum) == k){
        //         return maxSum;
        //     }
        // }
        // return low;
        while(low <= high){
            int mid = low +(high-low)/2;
            int partition = countPartition(nums, mid);
            if(partition>k){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return low;
    }
};
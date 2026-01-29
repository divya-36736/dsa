class Solution {
public:
    long long count(vector<int>&nums, int i){
        long long sum = 0;
        for(int num: nums){
            sum += (num + i - 1)/i;
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int maxval = *max_element(nums.begin(), nums.end());
        int ans = INT_MAX;
        int smallestDivisor = 1;
        int st = 1;
        int end = maxval;
        while(st<=end){
            int mid = st+(end-st)/2;
            int sum = count(nums, mid);
            if(sum <= threshold && ans>mid){
                ans = mid;
                end = mid-1;
            }
            else{
                st = mid+1;
            }
        }
        return ans;
    }
};
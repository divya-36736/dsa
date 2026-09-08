class Solution {
public:
    long long minOperations(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        for(int i = 1; i<n; i++){
            if(nums[i] < nums[i-1]){
                sum += (long long) nums[i-1]-nums[i];
            }
        }
        return sum;
    }
};
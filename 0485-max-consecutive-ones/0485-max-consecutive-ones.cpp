class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int maxi = INT_MIN;
        for(int i = 0; i<n; i++){
            if(nums[i] == 1){
                count++; 
            }
            else if(nums[i] == 0){
                count = 0;
            }
            maxi = max(count, maxi);
        }
        return maxi;
    }
};
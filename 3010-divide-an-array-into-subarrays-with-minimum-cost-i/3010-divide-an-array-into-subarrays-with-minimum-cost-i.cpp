class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];
        int min1 = INT_MAX;
        int min2 = INT_MAX;

        for(int i = 1; i<n; i++){
            if(min1 > nums[i]){
                min2 = min1;
                min1 = nums[i];
            }
            else if(min2 > nums[i]){
                min2 = nums[i];
            }
        }
        return sum+min1+min2;
    }
};
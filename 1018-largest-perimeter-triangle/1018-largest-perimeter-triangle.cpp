class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        //what is triangle rule 
        //sum of 2 sides must be greater than 3rd side
        sort(nums.begin(), nums.end(), greater<int>());
        for(int i = 0; i<n-2; i++){
            if(nums[i+1] + nums[i+2] > nums[i]) return nums[i]+nums[i+1]+nums[i+2];
        }
        return 0;
    }
};
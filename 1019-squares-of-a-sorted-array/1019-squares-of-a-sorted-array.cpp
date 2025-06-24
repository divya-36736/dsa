class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i<n; i++){
            nums[i] = nums[i]*nums[i];
        }
        sort(nums.begin(), nums.end());
        return nums;
    }
};
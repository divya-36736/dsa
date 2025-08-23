class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //1st we do this sort
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return nums[n-k];
    }
};
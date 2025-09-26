class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int diff = INT_MAX;
        for(int i = 0; i+k-1<n; i++){
            int mini = nums[i];
            int maxi = nums[i+k-1];
            diff = min(diff, maxi-mini);
        }
        return diff;
    }
};
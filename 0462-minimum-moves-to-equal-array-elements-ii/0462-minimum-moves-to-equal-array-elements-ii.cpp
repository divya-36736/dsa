class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int med = nums[n/2];
        int ops = 0;
        for(auto num:nums){
            ops += abs(num-med);
        }
        return ops;
    }
};
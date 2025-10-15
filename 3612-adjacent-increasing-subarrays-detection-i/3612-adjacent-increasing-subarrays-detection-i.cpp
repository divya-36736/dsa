class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int k1 = k-1;
        if(k1 == 0)return true;
        for(int j=k+1;j<nums.size();j++){
            if(nums[j] > nums[j-1] && nums[j-k] > nums[j-k-1])k1--;
            else k1 = k - 1;
            if(k1 == 0)return true;
        }
        return false;
    }
};
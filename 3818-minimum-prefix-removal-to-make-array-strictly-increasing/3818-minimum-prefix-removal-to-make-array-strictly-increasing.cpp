class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        for (int i = nums.size() - 1; i > 0; i--) {
            if (nums[i - 1] >= nums[i])
                return i;
        }
        return 0;
    }
};
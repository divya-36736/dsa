class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int maxOr = 0;
        
        // Step 1: Calculate the maximum OR value from all elements
        for (int num : nums) {
            maxOr |= num;
        }

        int count = 0;

        // Step 2: Go through all non-empty subsets using bitmasking
        for (int mask = 1; mask < (1 << n); ++mask) {
            int currentOr = 0;

            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    currentOr |= nums[i];
                }
            }

            if (currentOr == maxOr) {
                count++;
            }
        }

        return count;
    }
};

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int sum = 0;

        // Step 1: flip as many negatives as possible
        for (int i = 0; i < nums.size() && k > 0; i++) {
            if (nums[i] < 0) {
                nums[i] = -nums[i];
                k--;
            }
        }

        // Step 2: compute sum
        for (int num : nums) sum += num;

        // Step 3: if k is odd, flip the smallest absolute value element
        if (k % 2 == 1) {
            int smallest = *min_element(nums.begin(), nums.end());
            sum -= 2 * smallest;
        }

        return sum;
    }
};

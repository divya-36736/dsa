class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int a = n; // Initialize to n (case where n is missing)
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (nums[i] != i) {
                a = i; // Missing number is the index where nums[i] != i
                break; // Exit loop after finding the first mismatch
            }
        }
        return a;
    }
};
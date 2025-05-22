class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int a = nums[n - 1]; // Initialize a to last element
        int i = 0;
        int j = i + 1;
        if (n == 1) return nums[i];
        while (i < n - 1 && j < n) {
            if (nums[i] != nums[j]) {
                a = nums[i]; // Single number found
                break;
            }
            i += 2;
            j = i + 1;
        }
        return a;
    }
};
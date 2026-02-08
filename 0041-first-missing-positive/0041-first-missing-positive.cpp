class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        if (n == 1) return nums[0] == 1 ? 2 : 1;

        int i = 0;
        while (i < n && nums[i] <= 0) {
            i++;
        }

        int j = 1;
        while (i < n) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                i++;
                continue;
            }

            if (nums[i] != j) {
                return j;
            }
            j++;
            i++;
        }

        return j;
    }
};

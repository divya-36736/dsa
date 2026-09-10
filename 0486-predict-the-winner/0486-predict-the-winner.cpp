class Solution {
public:

    int solve(vector<int>& nums, int i, int j) {

        if(i == j) {
            return nums[i];
        }

        int takeLeft = nums[i] - solve(nums, i + 1, j);

        int takeRight = nums[j] - solve(nums, i, j - 1);

        return max(takeLeft, takeRight);
    }

    bool predictTheWinner(vector<int>& nums) {

        int n = nums.size();

        return solve(nums, 0, n - 1) >= 0;
    }
};
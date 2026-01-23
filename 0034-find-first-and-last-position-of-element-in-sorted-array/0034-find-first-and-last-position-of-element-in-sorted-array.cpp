class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans(2, -1);

        for (int i = 0; i < n; i++) {
            if (nums[i] == target) {
                if (ans[0] == -1) {
                    ans[0] = i;   // first occurrence
                }
                ans[1] = i;       // keep updating last occurrence
            }
        }
        return ans;
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>next(n+1, 0);
        vector<int>curr(n+1, 0);


        for (int i = n-1; i >= 0; i--) {
            for (int prev_i = i-1; prev_i >= -1; prev_i--) {

                int len = next[prev_i + 1]; // not take

                if (prev_i == -1 || nums[prev_i] < nums[i]) {
                    len = max(len, 1 + next[i+1]); // take
                }

                curr[prev_i + 1] = len;
            }
            next = curr;
        }
        return next[0];
    }
};

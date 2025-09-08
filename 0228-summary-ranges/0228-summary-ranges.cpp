class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n = nums.size();
        if (n == 0) return ans;

        int start = nums[0];
        for (int i = 1; i <= n; i++) {
            if (i == n || nums[i] != nums[i - 1] + 1) {
                int end = nums[i - 1];
                if (start == end) {
                    ans.push_back(to_string(start));
                } else {
                    ans.push_back(to_string(start) + "->" + to_string(end));
                }
                if (i < n) start = nums[i];
            }
        }
        return ans;
    }
};

class Solution {
public:
    void subs(int i, int n, int k, vector<vector<int>>& ans, vector<int>& ds, vector<int>& nums) {
        if(ds.size() == k) {
            if(n == 0) {
                ans.push_back(ds);
            }
            return;
        }
        for(int j = i; j < nums.size(); j++) {
            if(nums[j] > n) break;  // pruning
            ds.push_back(nums[j]);
            subs(j + 1, n - nums[j], k, ans, ds, nums);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums;
        for(int i = 1; i <= 9; i++) nums.push_back(i);

        vector<vector<int>> ans;
        vector<int> ds;
        subs(0, n, k, ans, ds, nums);
        return ans;
    }
};
